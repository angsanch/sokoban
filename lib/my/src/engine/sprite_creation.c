/*
** EPITECH PROJECT, 2023
** sprite_creation.c
** File description:
** Smart sprite creation
*/

#include "../../include/my.h"

void add_sprite(dn_scene *scene)
{
    scene->creation = create_sprite(scene);
}

void add_texture(dn_scene *scene, dn_texture *texture)
{
    sprite_link_texture(scene->creation, texture);
}

void add_functions(dn_scene *scene,
    void(*tick)(struct dn_sprite_container *, dn_envinfo *),
    void(*event)(struct dn_sprite_container *, dn_envinfo *))
{
    dn_sprite *sprite = scene->creation;

    sprite->tick = tick;
    sprite->event = event;
}

void add_push_sprite(dn_scene *scene)
{
    list_append(scene->sprites, scene->creation);
    scene->creation = NULL;
}

void add_data(dn_scene *scene, void *data, void(*destroy_data)(void *))
{
    sprite_add_data(scene->creation, data, destroy_data);
}
