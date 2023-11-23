/*
** EPITECH PROJECT, 2023
** my_show_word_array.c
** File description:
** Print string array
*/

#include "../../include/my.h"

void my_show_word_array(char *const *tab)
{
    size_t i = 0;

    while (tab[i] != 0){
        my_putstr(tab[i]);
        my_putchar('\n');
        i ++;
    }
}
