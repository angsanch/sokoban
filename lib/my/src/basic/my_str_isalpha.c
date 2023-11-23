/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** All alpha string
*/

#include <stdlib.h>

int my_isalpha(char c)
{
    int result = 0;

    result += c >= 'a' && c <= 'z';
    result += c >= 'A' && c <= 'Z';
    return (result > 0);
}

int my_str_isalpha(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (!my_isalpha(str[i]))
            return (0);
        i ++;
    }
    return (1);
}
