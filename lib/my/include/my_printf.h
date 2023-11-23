/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** Printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdlib.h>

//flags "-+ #0"
typedef struct data_parameter{
    char specifier;
    bool flags[5];
    int width;
    int precision;
    int length;
    size_t characters;
    char *str;
} parameter;

int my_printf(char const *format, ...);
char *genericf(char const *format, va_list *ap);
parameter *parse_parameter(char const *format, int *i);
void destroy_param(parameter *p);
char *my_lluitoa_base(unsigned long long int nb, char const *base,
    int min_len);

char *signed_decimal_integer(parameter *param, va_list *ap, int n);
char *unsigned_decimal_integer(parameter *param, va_list *ap, int n);
char *length_exporter(parameter *param, va_list *ap, int n);
char *character_print(parameter *param, va_list *ap, int n);
char *string_print(parameter *param, va_list *ap, int n);
char *pointer_print(parameter *param, va_list *ap, int n);
char *length_exporter(parameter *param, va_list *ap, int n);
char *print_percentage(parameter *param, va_list *ap, int n);

#endif
