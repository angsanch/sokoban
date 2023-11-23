/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** Print whether a number is positive or negative
*/

#include <unistd.h>

void my_isneg(int n)
{
    char c = (n >= 0) ? 'P' : 'N';

    write(1, &c, 1);
}
