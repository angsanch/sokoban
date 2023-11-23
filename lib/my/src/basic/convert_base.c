/*
** EPITECH PROJECT, 2023
** convert_base.c
** File description:
** Change the base of a number
*/

#include "../../include/my.h"

static size_t int_len_base(int nbr, int base)
{
    size_t i = 0;
    unsigned int n = nbr;

    if (nbr == 0)
        return (1);
    if (nbr < 0){
        i ++;
        n = -nbr;
    }
    while (n > 0){
        n /= base;
        i ++;
    }
    return (i);
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int nb = my_getnbr_base(nbr, base_from);
    unsigned int n = nb;
    int len_base = my_strlen(base_to);
    int result_len = int_len_base(n, len_base);
    char *result = malloc(sizeof(char) * (result_len + 1));

    if (result == NULL)
        return (NULL);
    if (nb < 0){
        n = -nb;
        result[0] = '-';
    }
    nb = 0;
    while (n > 0 || nb < 1){
        result[result_len - nb - 1] = base_to[n % len_base];
        n /= len_base;
        nb ++;
    }
    result[result_len] = 0;
    return (result);
}
