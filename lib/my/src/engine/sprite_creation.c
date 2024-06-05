/*
** EPITECH PROJECT, 2023
** sprite_creation.c
** File description:
** Smart sprite creation
*/

#include "../../include/engine_utils.h"

void add_sprite(dn_scene_t *scene, float x, float y)
{
    dn_sprite_t *sprite = create_sprite(scene);

    scene->creation = sprite;
    sprite->position.x = x;
    sprite->position.y = y;
}

void add_sprite_set_graphics(dn_scene_t *scene, char *texture_id,
    void(*config)(dn_sprite_t *))
{
    dn_texture_t *texture;

    if (texture_id) {
        texture = search_texture(scene, texture_id);
        sprite_link_texture(scene->creation, texture);
    }
    if (config != NULL)
        config(scene->creation);
}

void add_sprite_set_functions(dn_scene_t *scene,
    void(*tick)(struct dn_sprite_t_container *, dn_envinfo_t *),
    void(*event)(struct dn_sprite_t_container *, dn_envinfo_t *))
{
    dn_sprite_t *sprite = scene->creation;

    sprite->tick = tick;
    sprite->event = event;
}

void add_push_sprite(dn_scene_t *scene)
{
    scene->creation = NULL;
}

void add_sprite_set_data(dn_scene_t *scene, void *data,
    void(*destroy_data)(void *))
{
    sprite_add_data(scene->creation, data, destroy_data);
}
