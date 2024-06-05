/*
** EPITECH PROJECT, 2024
** collisions.c
** File description:
** Collide objects
*/

#include "../../include/engine_utils.h"

static int present(void *sprite_void, void *nothing)
{
    (void)nothing;
    return (((dn_sprite_t *)sprite_void)->collision);
}

static sfIntRect sprite_to_rect(dn_sprite_t *sprite)
{
    return ((sfIntRect){sprite->position.x,
            sprite->position.y,
            sprite->display.outline_size.x,
            sprite->display.outline_size.y});
}

static void check_collision(dn_sprite_t **sprites, l_list_t *colls,
    sfIntRect *rects, sfVector2i *indexes)
{
    dn_coll_sprites_t *col = NULL;

    if (sfIntRect_intersects(&rects[0], &rects[1], NULL)){
        col = malloc(sizeof(dn_coll_sprites_t) * 1);
        if (col == NULL)
            return;
        *col = (dn_coll_sprites_t){sprites[indexes->x]->id,
            sprites[indexes->y]->id};
        list_push(colls, col);
        col = NULL;
    }
}

static void collide(dn_sprite_t **sprites, size_t amount, l_list_t *colls)
{
    sfIntRect rects[2];
    sfVector2i sprites_index;

    (void)sprites;
    if (amount <= 1)
        return;
    for (size_t i = 0; i < amount - 1; i++){
        rects[0] = sprite_to_rect(sprites[i]);
        for (size_t j = i + 1; j < amount; j++){
            rects[1] = sprite_to_rect(sprites[j]);
            sprites_index = (sfVector2i){i, j};
            check_collision(sprites, colls, rects, &sprites_index);
        }
    }
}

static void separate_quarters(quarter_info_t *info, sfIntRect(*rects)[5],
    dn_sprite_t *(*quarters)[4][info->amount], int (*lens)[4])
{
    int collision;

    for (size_t i = 0; i < info->amount; i ++){
        (*rects)[4] = sprite_to_rect(info->sprites[i]);
        for (size_t j = 0; j < 4; j ++){
            collision = sfIntRect_intersects(&(*rects)[j], &(*rects)[4], NULL);
            (*quarters)[j][(*lens)[j]] = (dn_sprite_t *)
                ((size_t)info->sprites[i] * collision);
            (*lens)[j] += collision;
        }
    }
}

static void quarter(quarter_info_t *info, int d, l_list_t *colls)
{
    quarter_info_t next_inf;
    dn_sprite_t *quarters[4][info->amount];
    int lens[4] = {0, 0, 0, 0};
    int width = info->rect->width / 2;
    int height = info->rect->height / 2;
    sfIntRect *rect = info->rect;
    sfIntRect rects[5] = {{rect->left, rect->top, width, height},
        {rect->left + width, rect->top, width, height},
        {rect->left, rect->top + height, width, height},
        {rect->left + width, rect->top + height, width, height}, {0, 0, 0, 0}};

    if (info->amount <= 5 || d >= 4){
        collide(info->sprites, info->amount, colls);
        return;
    }
    separate_quarters(info, &rects, &quarters, &lens);
    for (size_t i = 0; i < 4; i++){
        next_inf = (quarter_info_t){quarters[i], lens[i], &rects[i]};
        quarter(&next_inf, d + 1, colls);
    }
}

void add_active(quarter_info_t *info, dn_window_t *window)
{
    for (l_elem_t *e = window->scene->sprites->first; e != NULL; e = e->next){
        if (present(e->content, NULL)){
            info->sprites[info->amount] = e->content;
            info->amount ++;
        }
    }
}

void collisions(dn_window_t *window)
{
    size_t active_objects;
    sfIntRect rect = {0, 0, window->resolution.x, window->resolution.y};
    quarter_info_t info = {NULL, 0, &rect};
    l_list_t *colls = list_create(&free);

    if (colls == NULL)
        return;
    if (window->manage_collision == NULL)
        return;
    active_objects = list_count_fulfil(window->scene->sprites, &present, NULL);
    if (active_objects == 0)
        return;
    info.sprites = malloc(sizeof(dn_sprite_t *) * active_objects);
    if (info.sprites == NULL)
        return;
    add_active(&info, window);
    quarter(&info, 0, colls);
    list_iter(colls, (void *)window->manage_collision, window);
    list_destroy(colls);
    free(info.sprites);
}

void window_collisions(dn_window_t *window,
    void (*manage)(dn_coll_sprites_t *, dn_window_t *))
{
    window->manage_collision = manage;
}
