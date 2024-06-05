/*
** EPITECH PROJECT, 2023
** prepare_board.c
** File description:
** Make board file usable
*/

#include "../include/sokoban.h"

static int analize_tile(board_t *b, size_t x, size_t y, tile_t **t)
{
    l_list_t *lists[] = {b->game.boxes, b->game.locations};

    switch (b->map[y][x]){
        case '#':
        case ' ':
            break;
        case 'X':
        case 'O':
            list_append(lists[b->map[y][x] == 'O'], *t);
            *t = NULL;
            break;
        case 'P':
            if (b->game.player.x != -1 || b->game.player.y != -1)
                return (0);
            b->game.player = **t;
            break;
        default:
            return (0);
    }
    return (1);
}

static int analize_chars(board_t *b, size_t y)
{
    size_t x = 0;
    tile_t *t = NULL;

    while (b->map[y][x] != '\0'){
        if (t == NULL)
            t = malloc(sizeof(tile_t) * 1);
        if (t == NULL)
            return (0);
        t->x = x;
        t->y = y;
        if (!analize_tile(b, x, y, &t)){
            free(t);
            return (0);
        }
        x ++;
    }
    if (t != NULL)
        free(t);
    return (1);
}

static int check_board(board_t *b)
{
    ssize_t y = 0;

    while (y < b->height){
        if (!analize_chars(b, y))
            return (0);
        y ++;
    }
    return (b->game.boxes->len >= b->game.locations->len);
}

static int parse_buffer(board_t *b)
{
    ssize_t i = 0;
    size_t len;
    char *next = b->buff;

    b->height = my_strchr_count(next, '\n');
    b->map = malloc(sizeof(char *) * b->height);
    if (b->map == NULL)
        return (0);
    while (i < b->height){
        b->map[i] = next;
        next = my_strchr(next, '\n') + 1;
        next[-1] = '\0';
        len = next - b->map[i] - 1;
        if (len > b->max_width)
            b->max_width = len;
        i ++;
    }
    return (check_board(b));
}

board_t *board_from_file(char const *path)
{
    board_t *b;

    b = create_empty_board();
    if (b == NULL)
        return (NULL);
    b->buff_size = file_to_buffer(path, &b->buff);
    if (b->buff_size == -1){
        destroy_board(b);
        return (NULL);
    }
    if (!parse_buffer(b)){
        destroy_board(b);
        return (NULL);
    }
    return (b);
}
