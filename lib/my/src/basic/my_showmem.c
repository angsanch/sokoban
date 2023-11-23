/*
** EPITECH PROJECT, 2023
** my_showmem.c
** File description:
** Show parsed memory
*/

#include "../../include/my.h"

static char *hexchar(char *c)
{
    if (*c > '9')
        *c += 39;
    return (c);
}

static void print_pointer(unsigned long pointer)
{
    unsigned long divisor = 1;
    int len = 8;
    char temp;

    while (len > 0){
        len --;
        divisor *= 16;
    }
    while (divisor > 0){
        temp = (pointer / divisor) + '0';
        write(1, hexchar(&temp), 1);
        pointer %= divisor;
        divisor /= 16;
    }
}

static void print_hex(const unsigned char *str, int length)
{
    int i = 0;
    char print[5] = {' ', ' ', ' ', ' ', ' '};

    while (i < 16){
        if (i < length){
            print[(i % 2) * 2] = str[i] / 16 + '0';
            print[(i % 2) * 2 + 1] = str[i] % 16 + '0';
            hexchar(&print[(i % 2) * 2]);
            hexchar(&print[(i % 2) * 2 + 1]);
        }
        if (i % 2 == 1){
            write(1, print, 5);
            print[0] = ' ';
            print[1] = ' ';
            print[2] = ' ';
            print[3] = ' ';
        }
        i ++;
    }
}

static void print_line(const char *str, int length)
{
    int i = 0;

    print_pointer((unsigned long)str);
    write(1, ": ", 2);
    print_hex((const unsigned char *)str, length);
    while (i < length){
        if (my_isprintable(str[i]))
            write(1, &str[i], 1);
        else
            write(1, ".", 1);
        i ++;
    }
    write(1, "\n", 1);
}

void my_showmem(char const *str, size_t size)
{
    while (size >= 16){
        print_line(str, 16);
        str += 16;
        size -= 16;
    }
    if (size > 0)
        print_line(str, size);
}
