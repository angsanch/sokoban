/*
** EPITECH PROJECT, 2023
** ticks.c
** File description:
** Advance a tick
*/

#include "../../include/engine_utils.h"

static void call_sprite_tick(void *sprite_void, void *env_void)
{
    dn_sprite_t *sprite = sprite_void;
    dn_envinfo_t *env = env_void;

    if (sprite->tick != NULL)
        (sprite->tick)(sprite, env);
}

static void call_sprite_event(void *sprite_void, void *env_void)
{
    dn_sprite_t *sprite = sprite_void;
    dn_envinfo_t *env = env_void;

    if (sprite->event != NULL)
        (sprite->event)(sprite, env);
}

static float get_timedelta(sfClock *clock)
{
    float timedelta = sfClock_getElapsedTime(clock).microseconds / 1000;

    sfClock_restart(clock);
    return (timedelta);
}

int tick_window(dn_window_t *window)
{
    sfEvent event;
    dn_envinfo_t env = {get_timedelta(window->clock), window, &event};

    sfRenderWindow_clear(window->window, sfBlack);
    list_iter(window->scene->sprites, &call_sprite_tick, &env);
    if (window->to_be_closed)
        return (0);
    while (sfRenderWindow_pollEvent(window->window, &event)){
        list_iter(window->scene->sprites, &call_sprite_event, &env);
        if (event.type == sfEvtClosed)
            return (0);
        if (event.type == sfEvtResized){
            window->size.x = event.size.width;
            window->size.y = event.size.height;
        }
    }
    collisions(window);
    list_iter(window->scene->sprites, &display_sprite, window);
    sfRenderWindow_display(window->window);
    return (1);
}
