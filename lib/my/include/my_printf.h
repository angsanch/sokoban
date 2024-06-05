/*
** EPITECH PROJECT, 2024
** my_printf.h
** File description:
** my_printf for external use
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

int my_printf(char const *format, ...);
int my_sprintf(char *str, char const *format, ...);
int my_dprintf(int fd, char const *format, ...);
int my_sbufferf(char **str, char const *format, ...);

#endif
