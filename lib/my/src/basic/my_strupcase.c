/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** Convert to upper case
*/

#include <stdlib.h>

void my_to_upper(char *chr)
{
    if (chr[0] >= 'a' && chr[0] <= 'z')
        chr[0] -= 32;
}

char *my_strupcase(char *str)
{
    size_t i = 0;

    while (str[i] != 0){
        my_to_upper(str + i);
        i ++;
    }
    return (str);
}
