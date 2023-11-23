/*
** EPITECH PROJECT, 2023
** my_strlowcase.c
** File description:
** Convert to lower case
*/

#include <stdlib.h>

void my_to_lower(char *chr)
{
    if (chr[0] >= 'A' && chr[0] <= 'Z')
        chr[0] += 32;
}

char *my_strlowcase(char *str)
{
    size_t i = 0;

    while (str[i] != 0){
        my_to_lower(str + i);
        i ++;
    }
    return (str);
}
