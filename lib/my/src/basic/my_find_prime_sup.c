/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** Next prime
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 2)
        return (2);
    if (nb % 2 == 0)
        nb ++;
    while (!my_is_prime(nb))
        nb += 2;
    return (nb);
}
