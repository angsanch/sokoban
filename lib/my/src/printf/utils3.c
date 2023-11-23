/*
** EPITECH PROJECT, 2023
** utils3.c
** File description:
** Useful functions 3
*/

#include <stdarg.h>
#include "../../include/data_parameter.h"

int print_percentage(parameter *param, va_list *ap, void(*put)(char))
{
    (void)(param);
    (void)(ap);
    (*put)('%');
    return (1);
}
