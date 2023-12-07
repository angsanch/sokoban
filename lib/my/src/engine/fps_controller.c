/*
** EPITECH PROJECT, 2023
** fps_controller.c
** File description:
** Control the amount of fps
*/

#include "../../include/my.h"

dn_fps *create_fps_limiter(float max)
{
    dn_fps *fps = malloc(sizeof(dn_fps) * 1);

    if (fps == NULL)
        return (NULL);
    fps->expected = 1 / max;
    fps->clock = sfClock_create();
    return (fps);
}

void next_frame(dn_fps *fps)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(fps->clock));

    if (elapsed < fps->expected)
        sfSleep(sfSeconds(fps->expected - elapsed));
    sfClock_restart(fps->clock);
}

void destroy_fps_limiter(dn_fps *fps)
{
    sfClock_destroy(fps->clock);
    free(fps);
}
