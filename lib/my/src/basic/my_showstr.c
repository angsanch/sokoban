/*
** EPITECH PROJECT, 2023
** my_showstr.c
** File description:
** Print unprintable as hexadecimal
*/

#include "../../include/my.h"

static void print_hex(char chr)
{
    unsigned char c;
    unsigned char temp;

    write(1, "\\", 1);
    c = chr;
    if (chr < 0){
        c = -chr;
        write(1, "-", 1);
    }
    temp = c / 16 + '0';
    if (temp > '9')
        temp += 39;
    write(1, &temp, 1);
    temp = c % 16 + '0';
    if (temp > '9')
        temp += 39;
    write(1, &temp, 1);
}

void my_showstr(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (my_isprintable(str[i]))
            write(1, str + i, 1);
        else
            print_hex(str[i]);
        i ++;
    }
}
