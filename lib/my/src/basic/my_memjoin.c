/*
** EPITECH PROJECT, 2024
** my_memjoin.c
** File description:
** Join 2 pieces of memory
*/

#include "../../include/basic_utils.h"

void *my_memjoin(const void *m1, size_t s1, const void *m2, size_t s2)
{
    void *result;

    result = my_calloc(sizeof(char), (s1 + s2 + 2));
    if (result == NULL)
        return (NULL);
    my_memcpy(result, m1, s1);
    my_memcpy(result + s1, m2, s2);
    return (result);
}
