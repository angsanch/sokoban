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

static tile *search_box(board *b, ssize_t x, ssize_t y)
{
    l_elem *e = b->game.boxes->first;
    tile *box;

    while (e != NULL){
        box = e->content;
        if (box->x == x && box->y == y)
            return (box);
        e = e->next;
    }
    return (NULL);
}

static void vertical_move(board *b, int y)
{
    tile *player = &b->game.player;
    tile new = *player;
    char m_tile = get_tile(b, new.x, new.y + y);
    char n_tile = get_tile(b, new.x, new.y + y + y);
    tile *box;

    if (m_tile == 'X'){
        box = search_box(b, player->x, player->y + y);
        if (n_tile == ' ' || n_tile == 'O'){
            player->y += y;
            box->y += y;
        }
    } else {
        new.y += y;
        if (m_tile == '#')
            new = *player;
        *player = new;
    }
}

static void horizontal_move(board *b, int x)
{
    tile *player = &b->game.player;
    tile new = *player;
    char m_tile = get_tile(b, new.x + x, new.y);
    char n_tile = get_tile(b, new.x + x + x, new.y);
    tile *box;

    if (m_tile == 'X'){
        box = search_box(b, player->x + x, player->y);
        if (n_tile == ' ' || n_tile == 'O'){
            player->x += x;
            box->x += x;
        }
    } else {
        new.x += x;
        if (m_tile == '#')
            new = *player;
        *player = new;
    }
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
    redraw(b);
}
