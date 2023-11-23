/*
** EPITECH PROJECT, 2023
** my_memset.c
** File description:
** Set memory
*/

#include <stdlib.h>

void *my_memset(void *b, int c, size_t len)
{
    size_t i = 0;
    char *strint = b;

    while (i < len){
        strint[i] = c;
        i ++;
    }
    return (b);
}
