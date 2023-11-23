/*
** EPITECH PROJECT, 2023
** my_strchr.c
** File description:
** Search char in string
*/

#include <stdlib.h>

int my_strchr_index(char const *str, char c)
{
    int i = 0;

    while (str[i] != 0){
        if (str[i] == c)
            return (i);
        i ++;
    }
    return (-1);
}

char *my_strchr(char const *str, char c)
{
    size_t i = 0;

    while (str[i] != '\0'){
        if (str[i] == c)
            return ((char *)(str + i));
        i ++;
    }
    return (0);
}
