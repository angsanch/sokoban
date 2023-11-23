/*
** EPITECH PROJECT, 2023
** my_strrchr.c
** File description:
** Reverse search a character
*/

#include <stdlib.h>

char *my_strrchr(char const *str, char c)
{
    size_t i = 0;
    size_t last = 0;

    while (str[i] != '\0'){
        if (str[i] == c)
            last = i;
        i ++;
    }
    return ((char *)str + last);
}
