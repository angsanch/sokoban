/*
** EPITECH PROJECT, 2023
** my_str_isnum.c
** File description:
** All numeric string
*/

#include <stdlib.h>

int my_isnumeric(char c)
{
    return (c >= '0' && c <= '9');
}

int my_str_isnum(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (!my_isnumeric(str[i]))
            return (0);
        i ++;
    }
    return (1);
}
