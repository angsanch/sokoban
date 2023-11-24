/*
** EPITECH PROJECT, 2023
** prepare_board.c
** File description:
** Make board file usable
*/

#include "../include/my.h"
#include "../include/sokoban.h"

static int analize_positions(board *b, size_t y)
{
    (void)b;
    (void)y;
    return (1);
}

static int analize_chars(board *b, size_t y)
{
    size_t x = 0;
    tile *t = NULL;

    while (b->map[y][x] != '\0'){
        if (t == NULL)
            t = malloc(sizeof(tile) * 1);
        if (t == NULL)
            return (0);
        t->x = x;
        t->y = y;
        switch (b->map[y][x]){
            case '#':
            case ' ':
                break;
            case 'X':
                list_append(b->game.boxes, t);
                t = NULL;
                break;
            case 'O':
                list_append(b->game.locations, t);
                t = NULL;
                break;
            case 'P':
                if (b->game.player.x + b->game.player.y != 0)
                    return (0);
                b->game.player = *t;
                break;
            default:
                return (0);
        }
        x ++;
    }
    if (t != NULL)
        free(t);
    return (1);
}

static int check_board(board *b)
{
    size_t y = 0;

    while (y < b->height){
        if (!(analize_positions(b, y) && analize_chars(b, y)))
            return (0);
        y ++;
    }
    return (b->game.boxes->len >= b->game.locations->len);
}

static int parse_buffer(board *b)
{
    size_t i = 0;
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

board *board_from_file(char const *path)
{
    board *b;

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
