/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** Strings to numbers
*/

#include "../../include/my.h"

int my_intlen(int nb)
{
    return (my_intlen_base(nb, 10));
}

int my_getnbr(char const *str)
{
    long result = 0;
    long n;
    int i = 0;
    int multiplicator = 1;

    while (!my_isnumeric(str[i])){
        if (str[i] != '+' && str[i] != ' ' && str[i] != '-')
            return (0);
        if (str[i] == '-')
            multiplicator *= -1;
        i ++;
    }
    while (my_isnumeric(str[i])){
        result = result * 10 + (str[i] - '0');
        n = result * multiplicator;
        if (n > 2147483647 || n < -2147483648)
            return (0);
        i ++;
    }
    return (result * multiplicator);
}
