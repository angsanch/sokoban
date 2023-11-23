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

typedef struct tile_position{
    size_t x;
    size_t y;
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

board *board_from_file(char const *file);
void destroy_board(board *b);

#endif
