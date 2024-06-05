/*
** EPITECH PROJECT, 2023
** sokoban.h
** File description:
** Necesary functions and structs
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include "basic.h"
    #include "linked_list.h"
    #include <stdlib.h>

    #define DOWN 258
    #define UP 259
    #define LEFT 260
    #define RIGHT 261

typedef struct tile_position {
    ssize_t x;
    ssize_t y;
} tile_t;

typedef struct game_info {
    l_list_t *boxes;
    l_list_t *locations;
    tile_t player;
} gameinf_t;

typedef struct board_data {
    size_t max_width;
    ssize_t height;
    ssize_t buff_size;
    char *buff;
    char **map;
    gameinf_t game;
} board_t;

board_t *create_empty_board(void);
board_t *board_from_file(char const *file);
void print_board(board_t *b);
tile_t *search_box(board_t *b, ssize_t x, ssize_t y);
void redraw(board_t *b);
void destroy_board(board_t *b);
ssize_t file_to_buffer(char const *path, char **buf);
int gameloop(char *path);
void move_soko(board_t *b, int key);

#endif
