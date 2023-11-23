/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Copy strings
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    size_t i = 0;

    while (src[i] != 0){
        dest[i] = src[i];
        i ++;
    }
    dest[i] = src[i];
    return (dest);
}
