/*
** EPITECH PROJECT, 2023
** links.c
** File description:
** Vincle structures
*/

#include "../../include/my.h"

static sfIntRect create_rect(sfTexture *texture,
    size_t x_tiles, size_t y_tiles)
{
    sfVector2u texture_size = sfTexture_getSize(texture);
    sfIntRect rect = {0, 0,
    texture_size.x / x_tiles, texture_size.y / y_tiles};

    return (rect);
}

void sprite_link_texture(dn_sprite *sprite, dn_texture *texture)
{
    sprite->texture = texture;
    sprite->rect = create_rect(texture->texture,
        texture->x_tiles, texture->y_tiles);
}

void sprite_add_data(dn_sprite *sprite, void *data,
    void(*destroy_data)(void *))
{
    sprite->data = data;
    sprite->destroy_data = destroy_data;
}

void sprite_set_rect(dn_sprite *sprite, size_t x, size_t y)
{
    sprite->rect.left = sprite->rect.width * x;
    sprite->rect.top = sprite->rect.height * y;
}

int is_on_sprite(dn_window *window, dn_sprite *sprite, int x, int y)
{
    int real_x = window->resolution.x * x / window->size.x;
    int real_y = window->resolution.y * y / window->size.y;
    int x_diff = real_x - sprite->position.x;
    int y_diff = real_y - sprite->position.y;

    return (x_diff >= 0 && x_diff <= sprite->rect.width &&
        y_diff >= 0 && y_diff <= sprite->rect.height);
}
