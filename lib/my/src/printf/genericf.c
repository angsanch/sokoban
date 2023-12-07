/*
** EPITECH PROJECT, 2023
** genericf.c
** File description:
** general function for my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stdio.h>

char const *specifiers = "diuoxXfFeEgGaAcspn%";
char *(*param_str[])(parameter *param, va_list *ap, int n) = {
    &signed_decimal_integer, &signed_decimal_integer,
    &unsigned_decimal_integer, &unsigned_decimal_integer,
    &unsigned_decimal_integer, &unsigned_decimal_integer,
    &signed_decimal_integer, &signed_decimal_integer,
    &signed_decimal_integer, &signed_decimal_integer,
    &signed_decimal_integer, &signed_decimal_integer,
    &signed_decimal_integer, &signed_decimal_integer,
    &character_print, &string_print,
    &pointer_print, &length_exporter,
    &print_percentage
};

static void list_destroy_param(void *p)
{
    destroy_param((parameter *)p);
}

char *string_parameter(parameter *param, va_list *ap, int *n)
{
    int index = my_strchr_index(specifiers, param->specifier);
    char *str;

    if (index == -1)
        return (NULL);
    if (param->width == -1)
        param->width = va_arg(*ap, int);
    if (param->precision == -2)
        param->precision = va_arg(*ap, int);
    str = (*param_str[index])(param, ap, *n);
    *n += my_strlen(str);
    return (str);
}

static l_list *parse_format(char const *format, va_list *ap, int *n)
{
    int i = 0;
    l_list *params = list_create(&list_destroy_param);
    parameter *new;

    if (params == NULL)
        return (NULL);
    while (format[i]){
        if (format[i] != '%' && format[i]){
            i ++;
            *n += 1;
            continue;
        }
        new = parse_parameter(format, &i);
        if (new == NULL || !list_append(params, new))
            return (list_destroy(params));
        new->str = string_parameter(new, ap, n);
        if (new->str == NULL)
            return (list_destroy(params));
    }
    return (params);
}

void prepare_result(char *result, l_list *params, char const *format)
{
    int i = 0;
    int n = 0;
    int len;
    parameter *p;

    while (format[i]){
        if (format[i] != '%' && format[i]){
            result[n] = format[i];
            i ++;
            n ++;
            continue;
        }
        p = params->first->content;
        len = my_strlen(p->str);
        my_strcpy(result + n, p->str);
        n += len;
        i += p->characters;
        list_pop_first(params);
    }
    result[n] = '\0';
}

char *genericf(char const *format, va_list *ap)
{
    int n = 0;
    l_list *params = parse_format(format, ap, &n);
    char *result = malloc(sizeof(char) * (n + 1));

    if (params == NULL)
        return (NULL);
    if (result != NULL)
        prepare_result(result, params, format);
    list_destroy(params);
    return (result);
}
