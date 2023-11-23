/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Find strings in strings
*/

#include "../../include/my.h"

char *my_strstr(char *str, char const *to_find)
{
    size_t i = 0;
    size_t str_len = my_strlen(str);
    size_t find_len = my_strlen(to_find);

    if (str_len < find_len)
        return (0);
    if (find_len == 0)
        return (str);
    while (i < str_len - find_len + 1){
        if (my_strncmp(str + i, to_find, find_len) == 0)
            return (str + i);
        i ++;
    }
    return (0);
}
