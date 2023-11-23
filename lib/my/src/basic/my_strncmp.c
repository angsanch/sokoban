/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** Compare n characters
*/

#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t i = 0;

    while ((s1[i] != 0 || s2[i] != 0) && i < n){
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i ++;
    }
    return (0);
}
