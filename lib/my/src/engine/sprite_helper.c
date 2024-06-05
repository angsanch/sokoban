/*
** EPITECH PROJECT, 2023
** links.c
** File description:
** Vincle structures
*/

#include "../../include/engine_utils.h"

static sfIntRect create_rect(sfTexture *texture,
    size_t x_tiles, size_t y_tiles)
{
    sfVector2u texture_size = sfTexture_getSize(texture);
    sfIntRect rect = {0, 0,
    texture_size.x / x_tiles, texture_size.y / y_tiles};

    return (rect);
}

void sprite_link_texture(dn_sprite_t *sprite, dn_texture_t *texture)
{
    sfIntRect rect = create_rect(texture->texture,
        texture->x_tiles, texture->y_tiles);
    sfVector2f halved = {rect.width / 2, rect.height / 2};

    sprite->display.texture = texture;
    sprite->display.rect = rect;
    sprite->display.outline_size = (sfVector2f){rect.width, rect.height};
    sprite->display.circle_size = MAX(rect.width, rect.height) / 2;
    sfSprite_setOrigin(sprite->sprite, halved);
    sfCircleShape_setOrigin(sprite->display.circle, halved);
    sprite->offset = (sfVector2f){-halved.x, -halved.y};
}

void sprite_add_data(dn_sprite_t *sprite, void *data,
    void(*destroy_data)(void *))
{
    sprite->data = data;
    sprite->destroy_data = destroy_data;
}

void sprite_set_rect(dn_sprite_t *sprite, size_t x, size_t y)
{
    sprite->display.rect.left = sprite->display.rect.width * x;
    sprite->display.rect.top = sprite->display.rect.height * y;
}

int is_on_sprite(dn_window_t *window, dn_sprite_t *sprite, int x, int y)
{
    int real_x = window->resolution.x * x / window->size.x;
    int real_y = window->resolution.y * y / window->size.y;
    int x_diff = real_x - sprite->position.x;
    int y_diff = real_y - sprite->position.y;

    return (x_diff >= 0 && x_diff <= sprite->display.rect.width &&
        y_diff >= 0 && y_diff <= sprite->display.rect.height);
}

void sprite_set_text(dn_sprite_t *sprite, char *str)
{
    sfText_setString(sprite->display.text, str);
}
