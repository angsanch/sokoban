/*
** EPITECH PROJECT, 2024
** my_memmove.c
** File description:
** Move overlaping memory
*/

#include "../../include/basic_utils.h"

void *my_memmove(void *dst, const void *src, size_t n)
{
    char *dstchr = dst;
    const char *srcchr = src;
    size_t i = 0;

    if (src > dst){
        my_memcpy(dst, src, n);
        return (dst);
    }
    if (dst == src)
        return (dst);
    while (i < n){
        dstchr[n - i - 1] = srcchr[n - i - 1];
        i ++;
    }
    return (dst);
}
