/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Length of a string
*/

#include <stdlib.h>

size_t my_strlen(char const *str)
{
    size_t i = 0;

    while (str[i] != 0)
        i ++;
    return (i);
}
