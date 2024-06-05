/*
** EPITECH PROJECT, 2024
** my_memchr.c
** File description:
** Find chars in memory
*/

int my_memchr_index(const void *m, int c, int len)
{
    int i = 0;
    unsigned char chr = c;
    const char *s = m;

    while (i < len){
        if (s[i] == chr)
            break;
        i ++;
    }
    if (i >= len)
        return (-1);
    if (s[i] == chr)
        return (i);
    else
        return (-1);
}
