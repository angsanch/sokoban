/*
** EPITECH PROJECT, 2023
** loop.c
** File description:
** Game loop
*/

#include "../include/sokoban.h"
#include <ncurses.h>

static void display_board(board_t *b)
{
    size_t x;
    ssize_t y;
    ssize_t i = 0;
    char *error = "The terminal is too small, please make it bigger";

    getmaxyx(stdscr, y, x);
    if (b->max_width <= x && b->height <= y){
        x = (x - b->max_width) / 2;
        y = (y - b->height) / 2;
        while (i < b->height){
            move(y + i, x);
            addstr(b->map[i]);
            i ++;
        }
    } else {
        move(y / 2, (x - my_strlen(error)) / 2);
        addstr(error);
    }
    refresh();
}

static int check_resize(void)
{
    static size_t px = 0;
    static size_t py = 0;
    size_t x;
    size_t y;
    int result;

    getmaxyx(stdscr, y, x);
    result = x != px || y != py;
    px = x;
    py = y;
    if (result)
        clear();
    return (result);
}

static int check_board(board_t *b)
{
    l_elem_t *e = b->game.locations->first;
    tile_t *location;

    while (e != NULL){
        location = e->content;
        if (search_box(b, location->x, location->y) == NULL)
            return (0);
        e = e->next;
    }
    return (1);
}

static int loop(char *path, board_t **b, int key_action)
{
    int unchanged = !key_action;

    if (*b == NULL){
        *b = board_from_file(path);
        unchanged = 0;
    }
    if (*b == NULL)
        return (-2);
    if (check_resize() || !unchanged){
        display_board(*b);
    }
    return (check_board(*b));
}

static int keys(board_t **b)
{
    int key = getch();

    if (key == 32){
        destroy_board(*b);
        *b = NULL;
    }
    if (key >= DOWN && key <= RIGHT)
        move_soko(*b, key);
    return (key);
}

int gameloop(char *path)
{
    board_t *b = NULL;
    int code = 0;
    int key = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (key != 'q'){
        code = loop(path, &b, key > 0);
        if (code != 0)
            break;
        key = keys(&b);
    }
    endwin();
    print_board(b);
    destroy_board(b);
    return (code);
}
