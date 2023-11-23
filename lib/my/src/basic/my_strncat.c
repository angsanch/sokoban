/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** Concat n characters
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, size_t nb)
{
    size_t len = my_strlen(dest);

    my_strncpy(dest + len, src, nb);
    return (dest);
}
