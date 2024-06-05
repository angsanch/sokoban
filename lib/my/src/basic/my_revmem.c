/*
** EPITECH PROJECT, 2024
** my_revmem.c
** File description:
** Reverse memory block
*/

#include "../../include/basic_utils.h"

void my_revmem(void *data, size_t size)
{
    size_t limit = size / 2;
    size_t i = 0;
    char *str = data;

    while (i < limit) {
        swap_chr(str + i, str + size - i - 1);
        i ++;
    }
}
