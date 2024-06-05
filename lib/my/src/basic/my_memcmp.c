/*
** EPITECH PROJECT, 2023
** my_memcmp.c
** File description:
** compare the memory.
*/

#include <stdlib.h>

int my_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i = 0;
    const char *str1 = s1;
    const char *str2 = s2;

    while (i != n){
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (0);
}
