/*
** EPITECH PROJECT, 2023
** my_getnbr_base.c
** File description:
** Strings to numbers
*/

#include "../../include/my.h"

int my_intlen_base(int nb, int base_len)
{
    unsigned int n = nb;
    int len = 0;

    if (nb == 0)
        return (1);
    if (nb < 0){
        len ++;
        n = -nb;
    }
    while (n){
        n /= base_len;
        len ++;
    }
    return (len);
}

int my_getnbr_base(char const *str, char const *base)
{
    int result = 0;
    int multiplicator = 1;
    size_t base_len = my_strlen(base);
    int power = 1;
    size_t i;

    if (str[0] == '-'){
        multiplicator = -1;
        str ++;
    }
    i = my_strlen(str) - 1;
    while (i + 1 > 0){
        result += power * my_strchr_index(base, str[i]);
        power *= base_len;
        i --;
    }
    return (result * multiplicator);
}
