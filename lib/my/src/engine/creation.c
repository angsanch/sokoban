/*
** EPITECH PROJECT, 2023
** creation.c
** File description:
** Allocate and prepare the structs
*/

#include "../../include/my.h"
#include "../../include/engine_utils.h"

dn_sound *create_sound(dn_scene *scene, char const *path)
{
    dn_sound *sound = malloc(sizeof(dn_sound) * 1);

    if (sound == NULL)
        return (NULL);
    sound->sound = sfSoundBuffer_createFromFile(path);
    if (sound->sound == NULL){
        free(sound);
        return (NULL);
    }
    if (!list_append(scene->sounds, sound)){
        free(sound);
        return (NULL);
    }
    sound->id = scene->id_sound;
    scene->id_sound += 1;
    return (sound);
}

dn_texture *create_texture(dn_scene *scene, char const *path,
    size_t x_tiles, size_t y_tiles)
{
    dn_texture *texture = malloc(sizeof(dn_texture) * 1);

    if (texture == NULL)
        return (NULL);
    texture->texture = sfTexture_createFromFile(path, NULL);
    if (texture->texture == NULL){
        free(texture);
        return (NULL);
    }
    if (!list_append(scene->textures, texture)){
        free(texture);
        return (NULL);
    }
    texture->id = scene->id_texture;
    scene->id_texture += 1;
    texture->x_tiles = x_tiles;
    texture->y_tiles = y_tiles;
    return (texture);
}

dn_sprite *create_sprite(dn_scene *scene)
{
    dn_sprite *sprite = malloc(sizeof(dn_sprite) * 1);

    if (sprite == NULL)
        return (NULL);
    if (!list_append(scene->sprites, sprite)){
        free(sprite);
        return (NULL);
    }
    sprite->id = scene->id_sprite;
    scene->id_sprite += 1;
    sprite->sprite = sfSprite_create();
    sprite->texture = NULL;
    sprite->tick = NULL;
    sprite->event = NULL;
    sprite->destroy_data = NULL;
    sprite->data = NULL;
    sprite->position.x = 0;
    sprite->position.y = 0;
    return (sprite);
}

dn_scene *create_scene(dn_window *window)
{
    dn_scene *scene = malloc(sizeof(dn_scene) * 1);

    if (scene == NULL)
        return (NULL);
    scene->music = NULL;
    scene->id_sprite = 0;
    scene->id_texture = 0;
    scene->id_sound = 0;
    scene->sprites = list_create(&destroy_sprite);
    scene->textures = list_create(&destroy_texture);
    scene->sounds = list_create(&destroy_sound);
    scene->creation = NULL;
    if (scene->sprites == NULL || scene->textures == NULL ||
        scene->sounds == NULL){
        destroy_scene(scene);
        return (NULL);
    }
    scene->id = window->id_scene;
    window->id_scene += 1;
    return (scene);
}

dn_window *create_window(int width, int height, char *name, sfUint32 style)
{
    sfVideoMode mode = {width, height, 32};
    dn_window *window = malloc(sizeof(dn_window) * 1);

    if (window == NULL)
        return (NULL);
    window->window = sfRenderWindow_create(mode, name, style, NULL);
    window->scene = NULL;
    window->id_scene = 0;
    window->resolution.x = width;
    window->resolution.y = height;
    window->size.x = width;
    window->size.y = height;
    window->scenes = list_create(&destroy_scene);
    if (window->scenes == NULL){
        free(window);
        return (NULL);
    }
    window->clock = sfClock_create();
    window->scene = create_scene(window);
    return (window);
}
