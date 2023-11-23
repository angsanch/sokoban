/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Print chars
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
