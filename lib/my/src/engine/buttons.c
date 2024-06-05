/*
** EPITECH PROJECT, 2024
** buttons.c
** File description:
** Simplify button creation
*/

#include "../../include/engine_utils.h"

//sfFloatRect bounds = sfText_getLocalBounds(sprite->display.text);
void config_button(dn_sprite_t *sprite)
{
    sprite->display.outline_size.x = 10;
    sprite->display.outline_size.y = 10;
    sprite->display.outline_color = sfWhite;
    sprite->display.draw_outline = true;
}

void create_button(dn_scene_t *scene, char *text, sfVector2f pos)
{
    add_sprite(scene, pos.x, pos.y);
    add_sprite_set_text_style(scene, sfWhite, 30);
    add_sprite_set_text(scene, text);
    add_sprite_set_graphics(scene, NULL, &config_button);
    add_push_sprite(scene);
}
