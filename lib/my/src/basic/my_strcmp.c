/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Compare strings
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    while (s1[i] == s2[i]){
        if (s1[i] == 0)
            break;
        i ++;
    }
    return (s1[i] - s2[i]);
}
