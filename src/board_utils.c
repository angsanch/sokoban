/*
** EPITECH PROJECT, 2023
** board_utils.c
** File description:
** Manage the boards
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/sokoban.h"

static void destroy_gameinf(gameinf *game)
{
    list_destroy(game->boxes);
    list_destroy(game->locations);
}

static int prepare_gameinf(gameinf *game)
{
    game->boxes = list_create(&free);
    game->locations = list_create(&free);
    game->player.x = 0;
    game->player.y = 0;
    if (game->boxes == NULL || game->boxes == NULL){
        destroy_gameinf(game);
        return (0);
    }
    return (1);
}

void destroy_board(board *b)
{
    destroy_gameinf(&b->game);
    free(b->map);
    free(b);
}

static board *create_empty_board(void)
{
    board *b = malloc(sizeof(board) * 1);

    if (b == NULL)
        return (NULL);
    b->buff_size = -1;
    b->buff = NULL;
    b->map = NULL;
    b->max_width = 0;
    b->height = 0;
    if (!prepare_gameinf(&b->game)){
        destroy_board(b);
        return (NULL);
    }
    return (b);
}

static ssize_t file_to_buffer(char const *path, char **buff)
{
    struct stat file_stat;
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return (-1);
    if (stat(path, &file_stat) != 0){
        close(fd);
        return (-1);
    }
    *buff = malloc(sizeof(char) * file_stat.st_size);
    if (*buff == NULL){
        close(fd);
        return (-1);
    }
    if (read(fd, *buff, file_stat.st_size) != file_stat.st_size){
        free(buff);
        close(fd);
        return (-1);
    }
    return (file_stat.st_size);
}

static int parse_buffer(board *b)
{
    size_t i = 0;
    char *next = b->buff;

    b->height = my_strchr_count(next, '\n');
    b->map = malloc(sizeof(char *) * b->height);
    if (b->map == NULL)
        return (0);
    while (i < b->height){
        b->map[i] = next;
        next = my_strchr(next, '\n') + 1;
        next[-1] = '\0';
        i ++;
    }
    return (1);
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
