/*
** EPITECH PROJECT, 2024
** my_strreplace.c
** File description:
** Replace substrings
*/

#include "../../include/basic_utils.h"

static size_t coincidences(char const *base, char const *key, size_t key_len)
{
    size_t i = 0;
    char *head = (char *)base;

    while (head != (char *)key_len) {
        head = (char *)(my_strstr(head, key) + key_len);
        i += head != (char *)key_len;
    }
    return (i);
}

static void thinker(char *base, char *key, char *replace, char *result)
{
    size_t jump;
    size_t offset = 0;
    size_t base_offset = 0;
    size_t base_len = my_strlen(base);
    size_t key_len = my_strlen(key);
    size_t repl_len = my_strlen(replace);
    size_t coins = coincidences(base, key, key_len);

    for (size_t i = 0; i < coins; i ++) {
        jump = my_strstr(base + base_offset, key) - (base + base_offset);
        my_memcpy(result + offset, base + base_offset, jump);
        base_offset += jump + key_len;
        offset += jump + repl_len;
        my_memcpy(result + offset - repl_len, replace, repl_len);
    }
    if (base_offset != base_len)
        my_memcpy(result + offset, base + base_offset, base_len - base_offset);
}

char *my_strreplace(char *base, char *key, char *replace)
{
    size_t base_len = my_strlen(base);
    size_t key_len = my_strlen(key);
    size_t repl_len = my_strlen(replace);
    size_t coins = coincidences(base, key, key_len);
    char *result = my_calloc((base_len + ((repl_len - key_len) * coins)) + 1,
        sizeof(char));

    if (result == NULL)
        return (NULL);
    thinker(base, key, replace, result);
    return (result);
}
