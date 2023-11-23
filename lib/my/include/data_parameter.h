/*
** EPITECH PROJECT, 2023
** data_parameter.h
** File description:
** patata
*/

#ifndef DATA_PARAMETER_H_
    #define DATA_PARAMETER_H_

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
} parameter;

#endif
