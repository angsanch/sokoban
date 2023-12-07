/*
** EPITECH PROJECT, 2023
** finder.c
** File description:
** Find in list
*/

#include "../../include/my.h"

dn_sound *search_sound(dn_scene *scene, size_t id)
{
    l_elem *e = scene->sounds->first;

    while (e){
        if (((dn_sound *)e->content)->id == id)
            return ((dn_sound *)e->content);
        e = e->next;
    }
    return (NULL);
}

dn_texture *search_texture(dn_scene *scene, size_t id)
{
    l_elem *e = scene->textures->first;

    while (e){
        if (((dn_texture *)e->content)->id == id)
            return ((dn_texture *)e->content);
        e = e->next;
    }
    return (NULL);
}

dn_sprite *search_sprite(dn_scene *scene, size_t id)
{
    l_elem *e = scene->sprites->first;

    while (e){
        if (((dn_sprite *)e->content)->id == id)
            return ((dn_sprite *)e->content);
        e = e->next;
    }
    return (NULL);
}

dn_scene *search_scene(dn_window *window, size_t id)
{
    l_elem *e = window->scenes->first;

    while (e){
        if (((dn_scene *)e->content)->id == id)
            return ((dn_scene *)e->content);
        e = e->next;
    }
    return (NULL);
}
