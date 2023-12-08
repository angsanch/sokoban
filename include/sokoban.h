/*
** EPITECH PROJECT, 2023
** sokoban.h
** File description:
** Necesary functions and structs
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include "my.h"
    #include <stdlib.h>

    #define DOWN 258
    #define UP 259
    #define LEFT 260
    #define RIGHT 261

typedef struct tile_position{
    ssize_t x;
    ssize_t y;
} tile;

typedef struct game_info{
    l_list *boxes;
    l_list *locations;
    tile player;
} gameinf;

typedef struct board_data{
    size_t max_width;
    size_t height;
    ssize_t buff_size;
    char *buff;
    char **map;
    gameinf game;
} board;

board *create_empty_board(void);
board *board_from_file(char const *file);
void print_board(board *b);
void destroy_board(board *b);
ssize_t file_to_buffer(char const *path, char **buf);
int gameloop(char *path);

#endif
