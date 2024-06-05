/*
** EPITECH PROJECT, 2023
** utils2.c
** File description:
** Useful functions 2
*/

#include "../../include/my_printf_utils.h"

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

static char *get_string(parameter_t *param, va_list *ap)
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

char *length_exporter(parameter_t *param, va_list *ap, int n)
{
    if (param->length == 0)
        *(va_arg(*ap, int *)) = n;
    if (param->length == 1)
        *(va_arg(*ap, signed char *)) = n;
    if (param->length == 2)
        *(va_arg(*ap, short int *)) = n;
    if (param->length == 3)
        *(va_arg(*ap, long int *)) = n;
    if (param->length == 4)
        *(va_arg(*ap, long long int *)) = n;
    if (param->length == 5)
        *(va_arg(*ap, intmax_t *)) = n;
    if (param->length == 6)
        *(va_arg(*ap, size_t *)) = n;
    if (param->length == 7)
        *(va_arg(*ap, ptrdiff_t *)) = n;
    return (my_strdup(""));
}

char *character_print(parameter_t *param, va_list *ap, int n)
{
    size_t len = 1;
    char *result;

    (void)n;
    if (param->width > 1)
        len = param->width;
    result = malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    if (param->flags[0]){
        result[0] = (char)va_arg(*ap, int);
        my_memset(result + 1, ' ', len - 1);
    } else {
        my_memset(result, ' ', len - 1);
        result[len - 1] = (char)va_arg(*ap, int);
    }
    result[len] = '\0';
    return (result);
}

static char *complex_string(parameter_t *param, char *str, int len)
{
    char *result = malloc(sizeof(char) * (param->width + 1));

    if (result == NULL)
        return (NULL);
    if (param->flags[0]){
        my_strcpy(result, str);
        my_memset(result + len, ' ', param->width - len);
        result[param->width] = 0;
    } else {
        my_memset(result, ' ', param->width - len);
        my_strcpy(result + param->width - len, str);
    }
    return (result);
}

char *string_print(parameter_t *param, va_list *ap, int n)
{
    int len;
    char *str;
    char *result;

    (void)n;
    str = get_string(param, ap);
    if (str == NULL)
        return (NULL);
    len = my_strlen(str);
    if (param->precision < len && param->precision >= 0){
        str[param->precision] = '\0';
        len = param->precision;
    }
    if (len >= param->width)
        return (str);
    result = complex_string(param, str, len);
    free(str);
    return (result);
}

char *pointer_print(parameter_t *param, va_list *ap, int n)
{
    unsigned long long int ptr = (unsigned long long int)va_arg(*ap, void *);
    char *parsed_number;
    char *result;
    char sign[] = "+0x";

    (void)n;
    parsed_number = my_lluitoa_base(ptr, "0123456789abcdef", param->precision);
    if (parsed_number == NULL)
        return (NULL);
    if ((!param->flags[1]) && param->flags[2])
        sign[0] = ' ';
    result = prepare_parts(param, sign + 1 - param->flags[2], parsed_number);
    free(parsed_number);
    return (result);
}

char *print_percentage(parameter_t *param, va_list *ap, int n)
{
    (void)param;
    (void)ap;
    (void)n;
    return (my_strdup("%"));
}
