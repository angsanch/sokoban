/*
** EPITECH PROJECT, 2023
** utils1.c
** File description:
** Useful functions
*/

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../../include/data_parameter.h"
#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stdio.h>

static long long int get_lld(int length, va_list *ap)
{
    switch (length){
        case 0:
        case 1:
        case 2:
            return ((long long int)va_arg(*ap, int));
        case 3:
            return ((long long int)va_arg(*ap, long int));
        case 4:
            return ((long long int)va_arg(*ap, long long int));
        case 5:
            return ((long long int)va_arg(*ap, intmax_t));
        case 6:
            return ((long long int)va_arg(*ap, size_t));
        case 7:
            return ((long long int)va_arg(*ap, ptrdiff_t));
        default:
            return ((long long int)va_arg(*ap, long int));
    }
}

static unsigned long long int get_llu(int length, va_list *ap)
{
    switch (length){
        case 0:
        case 1:
        case 2:
            return ((unsigned long long int)va_arg(*ap, unsigned int));
        case 3:
            return ((unsigned long long int)va_arg(*ap, unsigned long int));
        case 4:
            return ((unsigned long long int)va_arg(*ap,
                unsigned long long int));
        case 5:
            return ((unsigned long long int)va_arg(*ap, uintmax_t));
        case 6:
            return ((unsigned long long int)va_arg(*ap, size_t));
        case 7:
            return ((unsigned long long int)va_arg(*ap, ptrdiff_t));
        default:
            return ((unsigned long long int)va_arg(*ap, unsigned long int));
    }
}

static size_t my_numlen_base(unsigned long long int nb, size_t base_size)
{
    size_t size = 0;

    if (nb == 0)
        return (1);
    while (nb > 0){
        nb /= base_size;
        size ++;
    }
    return (size);
}

char *my_lluitoa_base(unsigned long long int nb, char const *base,
    int min_len)
{
    int i = 0;
    int base_size = my_strlen(base);
    int num_size = my_numlen_base(nb, base_size);
    char *result;

    if (min_len < 0)
        min_len = 0;
    if (num_size < min_len)
        num_size = min_len;
    result = malloc(sizeof(char) * (num_size + 1));
    if (result == NULL)
        return (NULL);
    my_memset(result, '0', num_size);
    while (i < num_size){
        result[num_size - i - 1] = base[nb % base_size];
        nb /= base_size;
        i ++;
    }
    result[num_size] = '\0';
    return (result);
}

size_t my_putstrp(char *str, void(*put)(char))
{
    size_t i = 0;

    while (str[i] != 0){
        (*put)(str[i]);
        i ++;
    }
    return (i);
}

int my_putnchrp(char c, int n, void(*put)(char))
{
    int i = 0;

    while (i < n){
        (*put)(c);
        i ++;
    }
    return (i);
}

static int print_num_flags(parameter *param, char *num, int plus,
    void(*put)(char))
{
    char sign[3] = "\0\0\0";

    if (!plus)
        sign[0] = '-';
    if (param->flags[1] && plus)
        sign[0] = '+';
    if (param->flags[2] && sign[0] == 0)
        sign[0] = ' ';
    if (param->flags[3]){
        if (param->specifier == 'o')
            my_strcpy(sign, "0");
        if (param->specifier == 'x')
            my_strcpy(sign, "0x");
        if (param->specifier == 'X')
            my_strcpy(sign, "0X");
    }
    return (print_parsed_nb(param, sign, num, put));
}

int signed_decimal_integer(parameter *param, va_list *ap, void(*put)(char),
    int *n)
{
    long long int num = get_lld(param->length, ap);
    unsigned long long int nb = num;
    char *text;

    (void)n;
    if (num < 0)
        nb = -num;
    text = my_lluitoa_base(nb, "0123456789", param->precision);
    if (text == NULL)
        return (0);
    nb = print_num_flags(param, text, num >= 0, put);
    free(text);
    return (nb);
}

int unsigned_decimal_integer(parameter *param, va_list *ap, void(*put)(char),
    int *n)
{
    unsigned long long int num = get_llu(param->length, ap);
    char *text;
    char base[] = "0123456789abcdef";

    (void)n;
    if (param->specifier == 'o')
        base[8] = 0;
    if (param->specifier == 'u')
        base[10] = 0;
    if (param->specifier == 'X')
        my_strupcase(base);
    text = my_lluitoa_base(num, base, param->precision);
    if (text == NULL)
        return (0);
    num = print_num_flags(param, text, 1, put);
    free(text);
    return (num);
}
