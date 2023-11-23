/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** Print strings
*/

#include <unistd.h>
#include <stdlib.h>

size_t my_putstr(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        write(1, str + i, 1);
        i ++;
    }
    return (i);
}
