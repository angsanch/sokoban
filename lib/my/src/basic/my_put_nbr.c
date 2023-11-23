/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Ints to terminal
*/

#include "../../include/my.h"

void my_put_nbr(int nb)
{
    unsigned int n;
    char c;

    n = nb;
    if (nb < 0){
        n = -nb;
        c = '-';
        write(1, &c, 1);
    }
    if (nb == 0)
        my_putchar('0');
    if (n / 10 != 0)
        my_put_nbr(n / 10);
    my_putchar('0' + (n % 10));
}
