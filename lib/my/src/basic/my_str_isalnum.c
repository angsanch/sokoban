/*
** EPITECH PROJECT, 2023
** my_str_isalnum.c
** File description:
** All alphanumeric string
*/

#include "../../include/basic_utils.h"

int my_isalnum(char c)
{
    return (my_isalpha(c) || my_isnumeric(c));
}

int my_str_isalnum(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (!my_isalnum(str[i]))
            return (0);
        i ++;
    }
    return (1);
}
