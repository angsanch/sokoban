/*
** EPITECH PROJECT, 2023
** setting_up.c
** File description:
** Search for squares
*/

#include <unistd.h>
#include "../include/my.h"
#include "../include/sokoban.h"

static int report_error(char *str)
{
    size_t i = 0;

    while (str[i] != '\0'){
        write(2, str + i, 1);
        i ++;
    }
    return (84);
}

int main(int argc, char **argv)
{
    board *b;

    if (argc != 2)
        return (report_error("Invalid amount of parameters.\n"));
    b = board_from_file(argv[1]);
    if (b == NULL)
        return (report_error("Error preparing the board\n"));
    return (0);
}
