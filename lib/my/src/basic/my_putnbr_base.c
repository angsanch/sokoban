/*
** EPITECH PROJECT, 2023
** my_putnbr_base.c
** File description:
** Print numbers in different bases
*/

#include "../../include/my.h"

static unsigned int get_divisor(unsigned int nbr, unsigned int base)
{
    unsigned int divisor = 1;

    while (nbr / base >= divisor)
        divisor *= base;
    return (divisor);
}

int my_putnbr_base(int nbr, char const *base)
{
    unsigned int n;
    unsigned int divisor;
    int len_base = my_strlen(base);

    n = nbr;
    if (nbr < 0){
        write(1, "-", 1);
        n = -nbr;
    }
    if (n == 0)
        write(1, "0", 1);
    divisor = get_divisor(n, len_base);
    while (divisor > 0){
        write(1, &base[n / divisor], 1);
        n %= divisor;
        divisor /= len_base;
    }
    return (0);
}
