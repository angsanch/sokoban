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

char *prepare_parts(parameter *param, char *sign, char *number)
{
    size_t len = my_strlen(sign) + my_strlen(number);
    size_t min_len = param->width;
    size_t used = min_len;
    char *result;

    if (len > min_len)
        used = len;
    result = malloc(sizeof(char) * (used + 1));
    if (result == NULL)
        return (NULL);
    if (!param->flags[0])
        my_memset(result, ' ', used - len);
    result[used - len] = '\0';
    my_strcat(result, sign);
    my_strcat(result, number);
    if (param->flags[0])
        my_memset(result + my_strlen(result), ' ', used - len);
    result[used] = '\0';
    return (result);
}

static void set_sign(parameter *param, int plus, char *sign)
{
    my_memset(sign, '\0', 3);
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
}

char *signed_decimal_integer(parameter *param, va_list *ap, int n)
{
    long long int num = get_lld(param->length, ap);
    unsigned long long int nb = num;
    size_t min_len = param->precision;
    char *parsed_number;
    char sign[3];
    char *result;

    (void)n;
    if (num < 0)
        nb = -num;
    set_sign(param, num >= 0, sign);
    if (param->flags[4] && !param->flags[0])
        min_len = param->width - my_strlen(sign);
    parsed_number = my_lluitoa_base(nb, "0123456789", min_len);
    if (parsed_number == NULL)
        return (NULL);
    result = prepare_parts(param, sign, parsed_number);
    free(parsed_number);
    return (result);
}

static void set_base(char specifier, char *base)
{
    switch (specifier){
        case 'u':
            my_strcpy(base, "0123456789");
            break;
        case 'o':
            my_strcpy(base, "01234567");
            break;
        case 'x':
            my_strcpy(base, "0123456789abcdef");
            break;
        case 'X':
            my_strcpy(base, "0123456789ABCDEF");
            break;
    }
}

char *unsigned_decimal_integer(parameter *param, va_list *ap, int n)
{
    unsigned long long int num = get_llu(param->length, ap);
    char *parsed_number;
    char base[17];
    char sign[3];
    size_t min_len = param->precision;
    char *result;

    (void)n;
    set_sign(param, 1, sign);
    set_base(param->specifier, base);
    parsed_number = my_lluitoa_base(num, base, min_len);
    if (parsed_number == NULL)
        return (NULL);
    result = prepare_parts(param, sign, parsed_number);
    free(parsed_number);
    return (result);
}
