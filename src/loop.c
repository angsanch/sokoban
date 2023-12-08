/*
** EPITECH PROJECT, 2023
** loop.c
** File description:
** Game loop
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include <ncurses.h>

static void display_board(board *b)
{
    size_t x;
    size_t y;
    size_t i = 0;
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

static int loop(char *path, board **b)
{
    int unchanged = 1;

    if (*b == NULL){
        *b = board_from_file(path);
        unchanged = 0;
    }
    if (*b == NULL)
        return (-2);
    if (check_resize() || !unchanged){
        display_board(*b);
    }
    return (0);
}

static int keys(board **b)
{
    int key = getch();

    if (key == 32){
        destroy_board(*b);
        *b = NULL;
    }
    if (key >= DOWN && key <= RIGHT)
        my_printf("move");
    return (key);
}

int gameloop(char *path)
{
    board *b = NULL;
    int code = 0;
    int key = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (key != 27){
        code = loop(path, &b);
        if (code < 0)
            break;
        key = keys(&b);
    }
    endwin();
    print_board(b);
    destroy_board(b);
    return (code);
}
