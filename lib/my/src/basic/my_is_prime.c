/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** Find primes
*/

int my_is_prime(int nb)
{
    int div = 2;

    if (nb <= 1)
        return (0);
    while (div <= nb / div){
        if (nb % div == 0)
            return (0);
        div ++;
    }
    return (1);
}
