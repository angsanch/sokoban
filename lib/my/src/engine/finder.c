/*
** EPITECH PROJECT, 2023
** finder.c
** File description:
** Find in list
*/

#include "../../include/engine_utils.h"

dn_texture_t *search_texture(dn_scene_t *scene, char *id)
{
    l_elem_t *e = scene->textures->first;

    while (e){
        if (my_strcmp(((dn_texture_t *)e->content)->id, id) == 0)
            return ((dn_texture_t *)e->content);
        e = e->next;
    }
    return (NULL);
}

dn_sprite_t *search_sprite(dn_scene_t *scene, size_t id)
{
    l_elem_t *e = scene->sprites->first;

    while (e){
        if (((dn_sprite_t *)e->content)->id == id)
            return ((dn_sprite_t *)e->content);
        e = e->next;
    }
    return (NULL);
}

int focus_scene(dn_window_t *window, char *id)
{
    l_elem_t *e = window->scenes->first;

    while (e){
        if (my_strcmp(((dn_scene_t *)e->content)->id, id) == 0){
            window->scene = e->content;
            return (1);
        }
        e = e->next;
    }
    return (0);
}
