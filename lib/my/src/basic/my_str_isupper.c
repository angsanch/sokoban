/*
** EPITECH PROJECT, 2023
** my_str_isupper.c
** File description:
** All upper case string
*/

#include <stdlib.h>

int my_isupper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int my_str_isupper(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (!my_isupper(str[i]))
            return (0);
        i ++;
    }
    return (1);
}
