/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** Square roots
*/

int my_compute_square_root(int nb)
{
    int sq = 1;

    while (sq <= nb / sq){
        if (sq * sq == nb)
            return (sq);
        sq ++;
    }
    return (0);
}
