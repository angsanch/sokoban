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
    char *result;
    int len;

    va_start(ap, format);
    result = genericf(format, &ap);
    va_end(ap);
    if (result == NULL)
        return (-1);
    len = my_putstr(result);
    free(result);
    return (len);
}
