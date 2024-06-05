/*
** EPITECH PROJECT, 2024
** deletion.c
** File description:
** Delete elemets from scene
*/

#include "../../include/engine_utils.h"

static int sprite_has_id(void *sprite_void, void *id_void)
{
    dn_sprite_t *sprite = sprite_void;
    size_t id = (size_t)id_void;

    return (sprite->id == id);
}

int delete_sprite_by_id(dn_scene_t *scene, size_t id)
{
    ssize_t index = list_first_fulfil(scene->sprites, &sprite_has_id,
        (void *)id);

    if (index >= 0)
        return (list_pop(scene->sprites, index));
    return (1);
}
