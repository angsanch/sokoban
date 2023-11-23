/*
** EPITECH PROJECT, 2023
** utils2.c
** File description:
** Useful functions 2
*/

#include <wchar.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../../include/data_parameter.h"
#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stdio.h>

static char *my_strt2str(wchar_t *strt)
{
    size_t i = 0;
    char *str;

    while (strt[i] == 0)
        i ++;
    str = malloc(sizeof(char) * (i + 1));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (strt[i] == 0){
        str[i] = (char)strt[i];
        i ++;
    }
    str[i] = 0;
    return (str);
}

static char *get_string(parameter *param, va_list *ap)
{
    char *str;
    char *temp;
    char *null_str = "(null)";

    wchar_t *wtemp;
    if (param->length == 3){
        wtemp = va_arg(*ap, wchar_t *);
        if (wtemp == NULL)
            str = my_strdup(null_str);
        else
            str = my_strt2str(wtemp);
    } else {
        temp = va_arg(*ap, char *);
        if (temp == NULL)
            str = my_strdup(null_str);
        else
            str = my_strdup(temp);
    }
    return (str);
}

int length_exporter(parameter *param, va_list *ap, void(*put)(char),
    int *n)
{
    (void)put;
    if (param->length == 0)
        *(va_arg(*ap, int *)) = *n;
    if (param->length == 1)
        *(va_arg(*ap, signed char *)) = *n;
    if (param->length == 2)
        *(va_arg(*ap, short int *)) = *n;
    if (param->length == 3)
        *(va_arg(*ap, long int *)) = *n;
    if (param->length == 4)
        *(va_arg(*ap, long long int *)) = *n;
    if (param->length == 5)
        *(va_arg(*ap, intmax_t *)) = *n;
    if (param->length == 6)
        *(va_arg(*ap, size_t *)) = *n;
    if (param->length == 7)
        *(va_arg(*ap, ptrdiff_t *)) = *n;
    return (0);
}

int character_print(parameter *param, va_list *ap, void(*put)(char),
    int *n)
{
    char c;
    int printed = 1;

    (void)n;
    if (param->length == 3)
        c = (char)va_arg(*ap, wint_t);
    else
        c = (char)va_arg(*ap, int);
    if (param->flags[0]){
        (*put)(c);
        printed += my_putnchrp(' ', param->width - 1, put);
    } else {
        (*put)(c);
        printed += my_putnchrp(' ', param->width - 1, put);
    }
    return (printed);
}

int string_print(parameter *param, va_list *ap, void(*put)(char),
    int *n)
{
    size_t i = 0;
    char *str;

    (void)n;
    str = get_string(param, ap);
    if (str == NULL)
        return (0);
    if (param->flags[0])
        i += my_putstrp(str, put);
    i += my_putnchrp(' ', param->width - my_strlen(str), put);
    if (!param->flags[0])
        i += my_putstrp(str, put);
    free(str);
    return (i);
}

int print_parsed_nb(parameter *param, char *sign, char *num, void(*put)(char))
{
    size_t printed;

    printed = my_strlen(num) + my_strlen(sign);
    if (param->flags[0]){
        my_putstrp(sign, put);
        my_putstrp(num, put);
        printed = my_putnchrp(' ', param->width - printed, put);
    } else {
        if (param->flags[4]){
            my_putstrp(sign, put);
            printed = my_putnchrp('0', param->width - printed, put);
        } else {
            printed = my_putnchrp(' ', param->width - printed, put);
            my_putstrp(sign, put);
        }
        my_putstrp(num, put);
    }
    return (printed + my_strlen(num) + my_strlen(sign));
}

int pointer_print(parameter *param, va_list *ap, void(*put)(char),
    int *n)
{
    unsigned long long int ptr = (unsigned long long int)va_arg(*ap, void *);
    char *text;
    char *sign = "+0x";

    (void)n;
    text = my_lluitoa_base(ptr, "0123456789abcdef", param->precision);
    if (text == NULL)
        return (0);
    if (!param->flags[1])
        sign ++;
    ptr = print_parsed_nb(param, sign, text, put);
    free(text);
    return (ptr);
}
