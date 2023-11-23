/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Word split
*/

#include "../../include/my.h"

static int is_alnum(char c)
{
    return (my_isalpha(c) || my_isnumeric(c));
}

static char *next_start(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (is_alnum(str[i]))
            break;
        i ++;
    }
    return ((char *)str + i);
}

static char *next_end(char const *str)
{
    size_t i = 0;

    while (str[i] != 0){
        if (!is_alnum(str[i]))
            break;
        i ++;
    }
    return ((char *)str + i);
}

static size_t count_words(char const *str)
{
    size_t i = 0;

    str = next_start(str);
    while (*str != 0){
        str = next_end(next_start(str));
        i ++;
    }
    str --;
    if (i > 1 && !is_alnum(*str))
        i --;
    return (i);
}

static char **free_all(char **result, size_t done)
{
    size_t i = 0;

    while (i < done){
        free(result[i]);
        i ++;
    }
    free(result);
    return (NULL);
}

char **my_str_to_word_array(char const *str)
{
    char **result;
    size_t i = 0;
    size_t len = count_words(str);
    char *end = (char *)str;

    result = malloc(sizeof(char *) * (len + 1));
    if (result == NULL)
        return (NULL);
    while (i < len){
        str = next_start(end);
        end = next_end(str);
        result[i] = malloc(sizeof(char) * (end - str + 1));
        if (result[i] == NULL)
            return (free_all(result, i));
        my_strncpy(result[i], str, end - str);
        result[i][end - str] = 0;
        i ++;
    }
    result[len] = NULL;
    return (result);
}
