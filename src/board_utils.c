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
    game->player.x = -1;
    game->player.y = -1;
    if (game->boxes == NULL || game->boxes == NULL){
        destroy_gameinf(game);
        return (0);
    }
    return (1);
}

void destroy_board(board *b)
{
    if (b == NULL)
        return;
    destroy_gameinf(&b->game);
    free(b->buff);
    free(b->map);
    free(b);
}

board *create_empty_board(void)
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

ssize_t file_to_buffer(char const *path, char **buff)
{
    struct stat file_stat;
    int fd = open(path, O_RDONLY);

    if (stat(path, &file_stat) != 0 || fd < 0){
        if (fd >= 0)
            close(fd);
        return (-1);
    }
    *buff = malloc(sizeof(char) * (file_stat.st_size + 1));
    (*buff)[file_stat.st_size] = '\0';
    if (*buff == NULL){
        close(fd);
        return (-1);
    }
    if (read(fd, *buff, file_stat.st_size) != file_stat.st_size){
        free(*buff);
        close(fd);
        return (-1);
    }
    return (file_stat.st_size);
}

void print_board(board *b)
{
    ssize_t i = 0;

    while (i < b->height){
        my_putstr(b->map[i]);
        my_putchar('\n');
        i ++;
    }
}
