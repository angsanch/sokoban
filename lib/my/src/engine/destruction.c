/*
** EPITECH PROJECT, 2023
** destruction.c
** File description:
** Destroy the structs
*/

#include "../../include/engine_utils.h"

void destroy_texture(dn_texture_t *texture)
{
    sfTexture_destroy(texture->texture);
    free(texture->id);
    free(texture);
}

void destroy_sprite(dn_sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfRectangleShape_destroy(sprite->display.outline);
    sfCircleShape_destroy(sprite->display.circle);
    sfText_destroy(sprite->display.text);
    sprite->destroy_data(sprite->data);
    free(sprite);
}

void destroy_scene(dn_scene_t *scene)
{
    list_destroy(scene->sprites);
    list_destroy(scene->textures);
    sfMusic_destroy(scene->music);
    free(scene->id);
    free(scene);
}

void destroy_window(dn_window_t *window)
{
    sfRenderWindow_close(window->window);
    sfRenderWindow_destroy(window->window);
    sfClock_destroy(window->clock);
    list_destroy(window->scenes);
    free(window);
}
