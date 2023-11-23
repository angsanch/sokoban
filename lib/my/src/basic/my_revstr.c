/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** Reverse string
*/

#include "../../include/my.h"

void swap_chr(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int size = my_strlen(str) - 1;
    int limit = size / 2 + 1;
    int i = 0;

    while (i < limit){
        swap_chr(str + i, str + size - i);
        i ++;
    }
    return (str);
}
