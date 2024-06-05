/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** print formats
*/

#include "../../include/my_printf_utils.h"

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

int my_sbufferf(char **str, char const *format, ...)
{
    va_list ap;

    va_start(ap, format);
    *str = genericf(format, &ap);
    va_end(ap);
    if (*str == NULL)
        return (-1);
    return (my_strlen(*str));
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
