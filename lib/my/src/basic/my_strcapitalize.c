/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** Capitalize texts
*/

#include "../../include/my.h"

char *my_strcapitalize(char *str)
{
    size_t i = 0;

    my_to_upper(str);
    while (str[i] != 0){
        i ++;
        if (my_isalpha(str[i - 1]) || my_isnumeric(str[i - 1]))
            my_to_lower(str + i);
        else
            my_to_upper(str + i);
    }
    return (str);
}
