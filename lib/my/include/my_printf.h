/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** Printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include "data_parameter.h"
    #include <stdarg.h>

int my_printf(char const *format, ...);
int genericf(void (*put)(char), char const *format, va_list *ap);
parameter *parse_parameter(char const *format, int *i);
void destroy_param(parameter *p);
char *my_lluitoa_base(unsigned long long int nb, char const *base,
    int min_len);
int my_putnchrp(char c, int n, void(*put)(char));
size_t my_putstrp(char *str, void(*put)(char));
int print_parsed_nb(parameter *param, char *sign, char *num, void(*put)(char));
int signed_decimal_integer(parameter *param, va_list *ap,
    void(*put)(char), int *n);
int unsigned_decimal_integer(parameter *param, va_list *ap,
    void(*put)(char), int *n);
int length_exporter(parameter *param, va_list *ap, void(*put)(char),
    int *n);
int character_print(parameter *param, va_list *ap, void(*put)(char),
    int *n);
int string_print(parameter *param, va_list *ap, void(*put)(char),
    int *n);
int pointer_print(parameter *param, va_list *ap, void(*put)(char),
    int *n);
int print_percentage(parameter *param, va_list *ap, void(*put)(char),
    int *n);


#endif
