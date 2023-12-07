/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** print formats
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"

static size_t my_dputstr(int fd, char const *str)
{
    size_t i = 0;

    while (str[i]){
        write(fd, str + i, 1);
        i ++;
    }
    return (i);
}

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

int my_sprintf(char *str, char const *format, ...)
{
    va_list ap;
    char *result;
    int len;

    va_start(ap, format);
    result = genericf(format, &ap);
    va_end(ap);
    if (result == NULL)
        return (-1);
    my_strcpy(str, result);
    len = my_strlen(result);
    free(result);
    return (len);
}

int my_dprintf(int fd, char const *format, ...)
{
    va_list ap;
    char *result;
    int len;

    va_start(ap, format);
    result = genericf(format, &ap);
    va_end(ap);
    if (result == NULL)
        return (-1);
    len = my_dputstr(fd, result);
    free(result);
    return (len);
}
