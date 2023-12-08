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
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("\t\t‘P’ for the player, ");
    my_putstr("‘X’ for boxes and ‘O’ for storage locations.\n");
    return (0);
}

static int game(char *path)
{
    int code = gameloop(path);

    if (code == 0)
        return (0);
    if (code == -1)
        return (report_error("An error has ocurred during game\n"));
    if (code == -2)
        return (report_error("Problem loading map\n"));
    return (84);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (report_error("Invalid amount of parameters.\n"));
    if (my_strcmp(argv[1], "-h") == 0)
        return (print_help());
    else
        return (game(argv[1]));
}
