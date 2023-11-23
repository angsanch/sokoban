/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** Concat two strings
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    size_t len = my_strlen(dest);

    my_strcpy(dest + len, src);
    return (dest);
}
