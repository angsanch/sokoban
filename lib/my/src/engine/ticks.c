/*
** EPITECH PROJECT, 2023
** ticks.c
** File description:
** Advance a tick
*/

#include "../../include/my.h"

static void call_sprite_tick(void *sprite_void, void *env_void)
{
    dn_sprite *sprite = sprite_void;
    dn_envinfo *env = env_void;

    if (sprite->tick != NULL)
        (sprite->tick)(sprite, env);
}

static void call_sprite_event(void *sprite_void, void *env_void)
{
    dn_sprite *sprite = sprite_void;
    dn_envinfo *env = env_void;

    if (sprite->event != NULL)
        (sprite->event)(sprite, env);
}

static void display_sprite(void *sprite_void, void *window_void)
{
    dn_sprite *sprite = sprite_void;
    sfRenderWindow *window = window_void;

    if (sprite->texture == NULL)
        return;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    sfSprite_setTexture(sprite->sprite, sprite->texture->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

static float get_timedelta(sfClock *clock)
{
    float timedelta = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    sfClock_restart(clock);
    return (timedelta);
}

int tick_window(dn_window *window)
{
    sfEvent event;
    dn_envinfo env = {get_timedelta(window->clock), window, &event};

    sfRenderWindow_clear(window->window, sfBlack);
    list_iter_data(window->scene->sprites, &env, &call_sprite_tick);
    while (sfRenderWindow_pollEvent(window->window, &event)){
        list_iter_data(window->scene->sprites, &env, &call_sprite_event);
        if (event.type == sfEvtClosed)
            return (0);
        if (event.type == sfEvtResized){
            window->size.x = event.size.width;
            window->size.y = event.size.height;
        }
    }
    list_iter_data(window->scene->sprites, window->window, &display_sprite);
    sfRenderWindow_display(window->window);
    return (1);
}
