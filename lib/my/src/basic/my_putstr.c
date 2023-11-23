/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** Print strings
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != 0){
        write(1, str + i, 1);
        i ++;
    }
}
