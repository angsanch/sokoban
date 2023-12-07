/*
** EPITECH PROJECT, 2023
** engine_utils.h
** File description:
** Engine tools
*/

#ifndef ENGINE_UTILS_H_
    #define ENGINE_UTILS_H_

    #include "structs.h"

void destroy_sound(void *sound);
void destroy_texture(void *texture);
void destroy_sprite(void *sprite);
void destroy_scene(void *scene);

#endif
