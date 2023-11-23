/*
** EPITECH PROJECT, 2023
** my_sort_int_array.c
** File description:
** Sort some ints
*/

#include "../../include/my.h"

static int buble(int *array, size_t size)
{
    size_t i = 0;
    int in_order;
    int sorted = 1;

    size --;
    while (i < size){
        in_order = array[i] <= array[i + 1];
        if (!in_order)
            my_swap(array + i, array + i + 1);
        sorted *= in_order;
        i ++;
    }
    return (sorted);
}

void my_sort_int_array(int *array, size_t size)
{
    while (!buble(array, size));
}
