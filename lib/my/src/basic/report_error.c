/*
** EPITECH PROJECT, 2024
** report_error.c
** File description:
** To make onliners
*/

#include "../../include/basic_utils.h"

int report_error(char *str, int response)
{
    write(2, str, my_strlen(str));
    return (response);
}
