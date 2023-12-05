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

static int print_help(void)
{
    my_putstr("USAGE\n"\
    "\t./my_sokoban map\n"\
    "DESCRIPTION\n"\
    "\tmap file representing the warehouse map, containing ‘#’ for walls,\n"\
    "\t\t‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.\n");
    return (84);
}

static int game(char *path)
{
    board *b = board_from_file(path);
    if (b == NULL)
        return (report_error("Error preparing the board\n"));
    destroy_board(b);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (report_error("Invalid amount of parameters.\n"));
    if (my_strcmp(argv[1], "-h") == 0)
        return(print_help());
    else
        return (game(argv[1]));
}
