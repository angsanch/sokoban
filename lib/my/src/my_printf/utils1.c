/*
** EPITECH PROJECT, 2023
** utils1.c
** File description:
** Useful functions
*/

#include "../../include/my_printf_utils.h"

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

    min_len = ((min_len - 1) * (min_len >= 0)) + 1;
    if (num_size < min_len)
        num_size = min_len;
    num_size *= !(min_len == 0 && nb == 0);
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

char *prepare_parts(parameter_t *param, char *sign, char *number)
{
    size_t len = my_strlen(sign) + my_strlen(number);
    size_t min_len = param->width;
    size_t used = min_len;
    char *result;

    if (len > min_len)
        used = len;
    result = my_calloc(sizeof(char), (used + 1));
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

char *signed_decimal_integer(parameter_t *param, va_list *ap, int n)
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

char *unsigned_decimal_integer(parameter_t *param, va_list *ap, int n)
{
    unsigned long long int num = get_llu(param->length, ap);
    char *parsed_number;
    char base[17];
    char sign[3];
    size_t min_len = param->precision;
    char *result;

    (void)n;
    set_sign(param, 1, sign);
    if (num == 0)
        sign[0] = 0;
    set_base(param->specifier, base);
    if (param->flags[4])
        min_len = param->width;
    parsed_number = my_lluitoa_base(num, base, min_len);
    if (parsed_number == NULL)
        return (NULL);
    result = prepare_parts(param, sign, parsed_number);
    free(parsed_number);
    return (result);
}
