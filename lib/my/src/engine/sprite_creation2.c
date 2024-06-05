/*
** EPITECH PROJECT, 2023
** sprite_creation.c
** File description:
** Smart sprite creation
*/

#include "../../include/engine_utils.h"

void add_sprite_set_text_style(dn_scene_t *scene, sfColor color, size_t size)
{
    dn_sprite_t *sprite = scene->creation;

    sprite->display.draw_text = true;
    sprite->display.text_color = color;
    if (size != 0)
        sprite->display.text_size = size;
}

void add_sprite_set_text(dn_scene_t *scene, char *text)
{
    sprite_set_text(scene->creation, text);
}
