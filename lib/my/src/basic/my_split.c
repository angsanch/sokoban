/*
** EPITECH PROJECT, 2024
** my_split.c
** File description:
** Split strings
*/

#include "../../include/basic_utils.h"

static char *find_next_start(const char *str, char delimiter)
{
    size_t i = 0;

    while (str[i] != 0){
        if (str[i] != delimiter)
            break;
        i ++;
    }
    return ((char *)str + i);
}

static char *find_next_end(const char *str, char delimiter)
{
    size_t i = 0;

    while (str[i] != 0){
        if (str[i] == delimiter)
            break;
        i ++;
    }
    return ((char *)str + i);
}

static int word_count(const char *str, char delimiter)
{
    int i = 0;

    while (*str != 0){
        str = find_next_start(str, delimiter);
        str = find_next_end(str, delimiter);
        if (*str != 0 || *(str - 1) != delimiter)
            i ++;
    }
    return (i);
}

char **free_string_array(char **result)
{
    int i = 0;

    if (result == NULL)
        return (NULL);
    while (result[i]){
        free(result[i]);
        i ++;
    }
    free(result);
    return (NULL);
}

char **my_split(char const *s, char c)
{
    int i = 0;
    int n = word_count(s, c);
    char **result = malloc(sizeof(char *) * (n + 1));
    char *end;

    if (result == NULL)
        return (NULL);
    my_memset(result, 0, sizeof(char *) * (n + 1));
    while (i < n){
        s = find_next_start(s, c);
        end = find_next_end(s, c);
        result[i] = malloc(sizeof(char) * (end - s + 1));
        if (result[i] == NULL)
            return (free_string_array(result));
        my_memcpy(result[i], s, end - s);
        result[i][end - s] = 0;
        i ++;
        s = end;
    }
    return (result);
}

size_t get_pointer_array_len(void *arr_in)
{
    size_t i = 0;
    void **arr = arr_in;

    for (; arr[i]; i++);
    return (i);
}
