/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** Printf
*/

#ifndef MY_PRINTF_UTILS_H_
    #define MY_PRINTF_UTILS_H_

    #include <stdarg.h>
    #include <stdint.h>
    #include <stddef.h>
    #include "linked_list.h"
    #include "basic.h"

//flags "-+ #0"
typedef struct data_parameter_t {
    char specifier;
    bool flags[5];
    int width;
    int precision;
    int length;
    size_t characters;
    char *str;
} parameter_t;

int my_printf(char const *format, ...);
char *genericf(char const *format, va_list *ap);
parameter_t *parse_parameter_t(char const *format, int *i);
void destroy_param(parameter_t *p);
char *prepare_parts(parameter_t *param, char *sign, char *number);
void set_base(char specifier, char *base);
void set_sign(parameter_t *param, int plus, char *sign);
char *my_lluitoa_base(unsigned long long int nb, char const *base,
    int min_len);

char *signed_decimal_integer(parameter_t *param, va_list *ap, int n);
char *unsigned_decimal_integer(parameter_t *param, va_list *ap, int n);
char *print_float(parameter_t *param, va_list *ap, int n);
char *length_exporter(parameter_t *param, va_list *ap, int n);
char *character_print(parameter_t *param, va_list *ap, int n);
char *string_print(parameter_t *param, va_list *ap, int n);
char *pointer_print(parameter_t *param, va_list *ap, int n);
char *length_exporter(parameter_t *param, va_list *ap, int n);
char *print_percentage(parameter_t *param, va_list *ap, int n);

#endif
