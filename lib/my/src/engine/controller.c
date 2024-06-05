/*
** EPITECH PROJECT, 2023
** controller.c
** File description:
** Control the amount of fps
*/

#include "../../include/engine_utils.h"

void limit_fps(dn_window_t *window, unsigned int limit)
{
    sfRenderWindow_setFramerateLimit(window->window, limit);
}
