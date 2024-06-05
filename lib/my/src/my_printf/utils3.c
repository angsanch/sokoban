/*
** EPITECH PROJECT, 2023
** utils3.c
** File description:
** Useful functions 3
*/

#include "../../include/my_printf_utils.h"

void set_base(char specifier, char *base)
{
    switch (specifier){
        case 'u':
        case 'f':
        case 'F':
        case 'e':
        case 'E':
            my_strcpy(base, "0123456789");
            break;
        case 'o':
            my_strcpy(base, "01234567");
            break;
        case 'x':
        case 'a':
            my_strcpy(base, "0123456789abcdef");
            break;
        case 'X':
        case 'A':
            my_strcpy(base, "0123456789ABCDEF");
            break;
    }
}

void set_sign(parameter_t *param, int plus, char *sign)
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

static char *decimals_to_string(parameter_t *param, long double nb, char *base)
{
    int base_size = my_strlen(base);
    long long int n;
    char *result = malloc(sizeof(char) * (param->precision + 2));
    int i = 0;

    if (result == NULL)
        return (NULL);
    n = nb;
    nb = nb - n;
    while (i < param->precision) {
        n = nb * base_size;
        nb = nb * base_size - n;
        result[i] = base[n];
        i++;
    }
    result[i] = 0;
    return (result);
}

static char *join_parts(parameter_t *param, char *entire, char *decimals)
{
    char *result;

    if (entire == NULL)
        return (NULL);
    if (my_strlen(decimals) == 0)
        if (param->flags[3])
            result = my_strjoin(entire, ".");
        else
            result = my_strdup(entire);
    else
        result = my_coolerstrjoin(3, entire, ".", decimals);
    return (result);
}

static char *float_to_string(parameter_t *param, long double num)
{
    char base[17];
    char *decimals;
    char *entire;
    char *result;

    set_base(param->specifier, base);
    if (num < 0)
        num *= -1;
    decimals = decimals_to_string(param, num, base);
    if (decimals == NULL)
        return (NULL);
    entire = my_lluitoa_base(num, base, (param->width - \
        my_strlen(decimals) - 1) * param->flags[4]);
    result = join_parts(param, entire, decimals);
    free(decimals);
    free(entire);
    return (result);
}

static char *add_spaces(parameter_t *param, char *raw)
{
    char *spacex;
    char *result;
    int offset = my_strlen(raw);

    if (param->width - offset > 0)
        offset = param->width - offset;
    else
        offset = 0;
    spacex = malloc(sizeof(char) * (offset + 1));
    if (spacex == NULL)
        return (NULL);
    my_memset(spacex, ' ', offset);
    spacex[offset] = 0;
    if (param->flags[0])
        result = my_strjoin(raw, spacex);
    else
        result = my_strjoin(spacex, raw);
    free(spacex);
    return (result);
}

static char *float_to_print(parameter_t *param, long double num)
{
    char *raw = float_to_string(param, num);
    char *result;
    char *spaced;
    char sign[3];

    if (raw == NULL)
        return (NULL);
    set_sign(param, num >= 0, sign);
    result = my_strjoin(sign, raw);
    if (result == NULL){
        free(raw);
        return (result);
    }
    spaced = add_spaces(param, result);
    free(result);
    free(raw);
    return (spaced);
}

char *print_float(parameter_t *param, va_list *ap, int n)
{
    long double num = (param->length == 8) ?
        va_arg(*ap, long double) : va_arg(*ap, double);

    (void)n;
    if (param->precision == -1)
        param->precision = 6;
    return (float_to_print(param, num));
}
