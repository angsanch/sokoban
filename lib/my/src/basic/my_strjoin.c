/*
** EPITECH PROJECT, 2023
** my_strjoin.c
** File description:
** join two strings or more
*/

#include "../../include/basic_utils.h"

char *my_strjoin(char *s1, char *s2)
{
    size_t l1 = my_strlen(s1);
    size_t l2 = my_strlen(s2);
    char *result = malloc(sizeof(char) * (l1 + l2 + 1));

    if (result == NULL)
        return (NULL);
    my_strcpy(result, s1);
    my_strcpy(result + l1, s2);
    result[l1 + l2] = '\0';
    return (result);
}

static char **get_strs(size_t n, va_list *ap, char **result)
{
    char **strs = malloc(sizeof(char *) * (n + 1));
    size_t i = 0;
    size_t total = 0;

    if (strs == NULL)
        return (NULL);
    while (i < n) {
        strs[i] = va_arg(*ap, char *);
        total += my_strlen(strs[i]);
        i ++;
    }
    *result = malloc(sizeof(char *) * (total + 1));
    if (*result == NULL){
        free(strs);
        return (NULL);
    }
    return (strs);
}

char *my_coolerstrjoin(size_t n, ...)
{
    char **strs;
    char *result;
    size_t total = 0;
    size_t i = 0;
    va_list ap;

    va_start(ap, n);
    strs = get_strs(n, &ap, &result);
    va_end(ap);
    if (strs == NULL)
        return (NULL);
    while (i < n) {
        my_strcpy(result + total, strs[i]);
        total += my_strlen(strs[i]);
        i ++;
    }
    result[total] = 0;
    free(strs);
    return (result);
}
