/*
** EPITECH PROJECT, 2023
** my_memcpy.c
** File description:
** Copy memory
*/

#include <stdlib.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    char *destchr = dest;
    const char *srcchr = src;

    if (dest == NULL && src == NULL)
        return (NULL);
    while (i < n){
        destchr[i] = srcchr[i];
        i ++;
    }
    return (dest);
}
