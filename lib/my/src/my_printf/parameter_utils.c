/*
** EPITECH PROJECT, 2023
** parse_parameter_t.c
** File description:
** Parse data into struct
*/

#include "../../include/my_printf_utils.h"

static char flags_called(char const *format, parameter_t *p, int i)
{
    int index = my_strchr_index("-+ #0", format[i]);

    while (index != -1){
        p->flags[index] = 1;
        index = my_strchr_index("-+ #0", format[i]);
        if (index >= 0)
            i++;
    }
    return (i);
}

static char width_called(char const *format, parameter_t *p, int i)
{
    if (format[i] == '*'){
        p->width = -1;
        return (i + 1);
    }
    if (!my_isnumeric(format[i]))
        return (i);
    p->width = my_getnbr(format + i);
    return (my_intlen(p->width) + i);
}

static int precision_called(char const *format, parameter_t *p, int i)
{
    if (format[i] != '.')
        return (i);
    i++;
    if (format[i] == '*'){
        p->precision = -2;
        return (i + 1);
    }
    if (!my_isnumeric(format[i])){
        p->precision = 0;
        return (i);
    }
    p->precision = my_getnbr(format + i);
    return (my_intlen(p->precision) + i);
}

static int length_called(char const *format, parameter_t *p, int i)
{
    p->length = my_strchr_index("hhlljztL", format[i]) + 1;
    if (p->length == 0)
        return (i);
    if (p->length == 1){
        if (format[i + 1] != 'h'){
            p->length ++;
            return (i + 1);
        } else
            return (i + 2);
    }
    if (p->length == 3){
        if (format[i + 1] != 'l')
            return (i + 1);
        else {
            p->length ++;
            return (i + 2);
        }
    }
    return (i + 1);
}

parameter_t *create_param(void)
{
    int i = 0;
    parameter_t *p = malloc(sizeof(parameter_t) * 1);

    if (p == NULL)
        return (NULL);
    p->specifier = 0;
    while (i < 5){
        p->flags[i] = 0;
        i ++;
    }
    p->width = 0;
    p->precision = -1;
    p->length = 0;
    p->str = NULL;
    return (p);
}

void destroy_param(parameter_t *p)
{
    free(p->str);
    free(p);
}

int param_eq(parameter_t *p1, parameter_t *p2)
{
    int i = 0;

    if (p1->specifier != p2->specifier)
        return (0);
    while (i < 5){
        if (p1->flags[i] != p2->flags[i])
            return (0);
        i++;
    }
    if (p1->width != p2->width)
        return (0);
    if (p1->precision != p2->precision)
        return (0);
    if (p1->length != p2->length)
        return (0);
    return (1);
}

parameter_t *parse_parameter_t(char const *format, int *i)
{
    parameter_t *data = create_param();

    if (data == NULL)
        return (NULL);
    data->characters = *i;
    *i += 1;
    *i = flags_called(format, data, *i);
    *i = width_called(format, data, *i);
    *i = precision_called(format, data, *i);
    *i = length_called(format, data, *i);
    data->specifier = format[*i];
    if (format[*i] != '\0')
        *i += 1;
    data->characters = *i - data->characters;
    return (data);
}
