/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** Movent in game
*/

#include "../include/sokoban.h"
#include "../include/my.h"

static char get_tile(board *b, ssize_t x, ssize_t y)
{
    ssize_t line_width;

    if (y < 0 || y >= b->height)
        return ('#');
    line_width = my_strlen(b->map[y]);
    if (x < 0 || x >= line_width)
        return ('#');
    return (b->map[y][x]);
}

/*static void move(board *b, int x, int y)
{
    ssize_t *px = &b->game.player.x;
    ssize_t *py = &b->game.player.y;

    b->map[*py][*px] = ' ';
    *px += x;
    *py += y;
    if (*py < 0)
        *py = 0;
    if (*py >= b->height)
        *py = b->height - 1;
    if (*px < 0)
        *px = 0;
    if (!b->map[*py][*px])
        *px = my_strlen(b->);
    b->map[*py][*px] = 'P';
}*/

static void vertical_move(board *b, int y)
{
    tile *player = &b->game.player;
    tile new = *player;

    new.y += y;
    if (get_tile(b, new.x, new.y) == '#')
        new = *player;
    b->map[player->y][player->x] = ' ';
    b->map[new.y][new.x] = 'P';
    *player = new;
}

static void horizontal_move(board *b, int x)
{
    tile *player = &b->game.player;
    tile new = *player;

    new.x += x;
    if (get_tile(b, new.x, new.y) == '#')
        new = *player;
    b->map[player->y][player->x] = ' ';
    b->map[new.y][new.x] = 'P';
    *player = new;
}

void move_soko(board *b, int key)
{
    switch (key){
        case UP:
            vertical_move(b, -1);
            break;
        case DOWN:
            vertical_move(b, 1);
            break;
        case LEFT:
            horizontal_move(b, -1);
            break;
        case RIGHT:
            horizontal_move(b, 1);
            break;
    }
}
