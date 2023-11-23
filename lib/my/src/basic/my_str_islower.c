/*
** EPITECH PROJECT, 2023
** my_str_islower.c
** File description:
** All lower case string
*/

#include <stdlib.h>

int my_islower(char c)
{
    return (c >= 'a' && c <= 'z');
}

int my_str_islower(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (!my_islower(str[i]))
            return (0);
        i ++;
    }
    return (1);
}
