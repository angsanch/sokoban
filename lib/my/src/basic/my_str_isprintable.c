/*
** EPITECH PROJECT, 2023
** my_str_isprintable.c
** File description:
** All printable string
*/

#include <stdlib.h>

int my_isprintable(char c)
{
    return (c >= ' ' && c <= '~');
}

int my_str_isprintable(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (!my_isprintable(str[i]))
            return (0);
        i ++;
    }
    return (1);
}
