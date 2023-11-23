/*
** EPITECH PROJECT, 2023
** genericf.c
** File description:
** general function for my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/data_parameter.h"
#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <stdio.h>

char const *specifiers = "diuoxXfFeEgGaAcspn%";
int(*prints[])(parameter *param, va_list *ap, void(*put)(char), int *n) = {
    &signed_decimal_integer, &signed_decimal_integer,
    &unsigned_decimal_integer, &unsigned_decimal_integer,
    &unsigned_decimal_integer, &unsigned_decimal_integer,
    &length_exporter, &length_exporter,
    &length_exporter, &length_exporter,
    &length_exporter, &length_exporter,
    &length_exporter, &length_exporter,
    &character_print, &string_print,
    &pointer_print, &length_exporter,
    &print_percentage
};

static int print_until_parameter(char const *format, int *i, void(*put)(char))
{
    int n = 0;

    while (format[*i] != '\0'){
        if (format[*i] != '%'){
            (*put)(format[*i]);
            *i += 1;
            n ++;
            continue;
        }
        break;
    }
    return (n);
}

static void nothing(char c)
{
    (void)c;
}

static int param_amount(char const *format)
{
    int i = 0;
    int n = 0;

    while (format[i] != '\0'){
        print_until_parameter(format, &i, &nothing);
        if (format[i] != '\0'){
            destroy_param(parse_parameter(format, &i));
            n ++;
        }
    }
    return (n);
}

static parameter **free_params(parameter **params)
{
    size_t i = 0;

    while (params[i] != NULL){
        destroy_param(params[i]);
        i ++;
    }
    free(params);
    return (NULL);
}

static parameter **parse_format(char const *format)
{
    int n = param_amount(format);
    int p = 0;
    int i = 0;
    parameter **params = malloc(sizeof(parameter *) * (n + 1));

    if (params == NULL)
        return (NULL);
    while (p < n){
        print_until_parameter(format, &i, &nothing);
        params[p] = parse_parameter(format, &i);
        params[p + 1] = NULL;
        if (my_strchr_index(specifiers, params[p]->specifier) < 0 ||
            params[p] == NULL)
            return (free_params(params));
        p ++;
    }
    params[n] = NULL;
    return (params);
}

void print_parameter(parameter *param, va_list *ap, void(*put)(char), int *n)
{
    int index = my_strchr_index(specifiers, param->specifier);

    if (index == -1)
        return;
    if (param->width == -1)
        param->width = va_arg(*ap, int);
    if (param->precision == -2)
        param->precision = va_arg(*ap, int);
    *n += (*prints[index])(param, ap, put, n);
}

int genericf(void (*put)(char), char const *format, va_list *ap)
{
    int i = 0;
    int n = 0;
    size_t p = 0;
    parameter **params = parse_format(format);

    if (params == NULL)
        return (-1);
    while (format[i] != '\0'){
        n += print_until_parameter(format, &i, put);
        if (params[p] != NULL && format[i] != 0){
            print_parameter(params[p], ap, put, &n);
            i += params[p]->characters;
            p ++;
        }
    }
    free_params(params);
    return (n);
}
