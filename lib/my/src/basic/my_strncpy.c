/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Copy n bytes
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, size_t n)
{
    size_t i = 0;

    while (i < n){
        dest[i] = src[i];
        if (src[i] == 0)
            break;
        i ++;
    }
    return (dest);
}
