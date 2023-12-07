/*
** EPITECH PROJECT, 2023
** my_strchr.c
** File description:
** Search char in string
*/

#include <stdlib.h>

ssize_t my_strchr_index(char const *str, char c)
{
    ssize_t i = 0;

    while (str[i] != 0){
        if (str[i] == c)
            return (i);
        i ++;
    }
    return (-1);
}

size_t my_strchr_count(char const *str, char c)
{
    size_t i = 0;
    size_t count = 0;

    while (str[i] != '\0'){
        count += str[i] == c;
        i ++;
    }
    return (count);
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

size_t my_strchr_count_consecutive(char const *str)
{
    size_t i = 0;
    char c = str[0];

    while (str[i] && str[i] == c)
        i ++;
    return (i);
}
