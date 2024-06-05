/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** Duplicate string
*/

#include "../../include/basic_utils.h"

char *my_strdup(char const *src)
{
    size_t len = my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * len);

    if (result == NULL)
        return (NULL);
    my_strcpy(result, src);
    return (result);
}
