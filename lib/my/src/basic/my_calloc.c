/*
** EPITECH PROJECT, 2023
** my_calloc.c
** File description:
** Allocate and clean
*/

#include "../../include/basic_utils.h"

void *my_calloc(size_t count, size_t size)
{
    size_t space = count * size;
    void *result;

    if (SIZE_MAX == count || SIZE_MAX == size)
        return (NULL);
    result = malloc(space);
    if (result == NULL)
        return (NULL);
    my_memset(result, 0, space);
    return (result);
}
