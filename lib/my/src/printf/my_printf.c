/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** print formats
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"

int my_printf(char const *format, ...)
{
    va_list ap;
    int printed;

    va_start(ap, format);
    printed = genericf(&my_putchar, format, &ap);
    va_end(ap);
    return (printed);
}
