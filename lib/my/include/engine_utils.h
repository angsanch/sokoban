/*
** EPITECH PROJECT, 2023
** engine_utils.h
** File description:
** Engine tools
*/

#ifndef ENGINE_UTILS_H_
    #define ENGINE_UTILS_H_

    #include "engine.h"
    #include "macros.h"

typedef struct collision_quarter {
    dn_sprite_t **sprites;
    size_t amount;
    sfIntRect *rect;
} quarter_info_t;

void destroy_texture(dn_texture_t *texture);
void destroy_sprite(dn_sprite_t *sprite);
void destroy_scene(dn_scene_t *scene);
void collisions(dn_window_t *window);

#endif
