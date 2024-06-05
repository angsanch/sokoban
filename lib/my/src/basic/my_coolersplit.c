/*
** EPITECH PROJECT, 2024
** my_coolersplit.c
** File description:
** im doing this drunk
*/

#include "../../include/basic_utils.h"

static size_t find_next_start(splited_t *spl)
{
    size_t i = 0;

    while (spl->str[spl->offset + i] != 0){
        if (!my_strchr(spl->separators, spl->str[spl->offset + i]))
            break;
        i ++;
    }
    return (i);
}

static ssize_t find_next_end(splited_t *spl)
{
    ssize_t i = 0;
    char l;

    while (spl->str[spl->offset + i] != 0){
        l = spl->str[spl->offset + i];
        if (spl->on_block == 0 && (l == '\'' || l == '\"')) {
            spl->on_block = l;
            l = 0;
        }
        if (spl->on_block == l)
            spl->on_block = 0;
        if (my_strchr(spl->separators, spl->str[spl->offset + i]) &&
            !spl->on_block)
            break;
        i ++;
    }
    return ((spl->on_block) ? -1 : i);
}

static int word_count(splited_t *spl)
{
    int i = 0;
    ssize_t end;

    while (spl->str[spl->offset] != 0){
        spl->offset += find_next_start(spl);
        end = find_next_end(spl);
        if (end < 0)
            return (-1);
        spl->offset += end;
        if (spl->str[spl->offset] != 0 ||
            !my_strchr(spl->separators, spl->str[spl->offset - 1]))
            i ++;
    }
    return (i);
}

void copy_without_quotations(char *dst, char const *src, size_t n)
{
    size_t d = 0;
    size_t s = 0;
    char p_block = 0;
    char block = 0;
    char l;

    while (s < n) {
        p_block = block;
        l = src[s];
        if (block == 0 && (l == '\'' || l == '\"')) {
            block = l;
            l = 0;
        }
        block = (block == l) ? 0 : block;
        if (p_block == block)
            dst[d] = src[s];
        d += p_block == block;
        s ++;
    }
    dst[d] = '\0';
}

static void *delete_splited_t(splited_t *spl, int delete_result)
{
    if (spl == NULL)
        return (NULL);
    if (delete_result)
        free_string_array(spl->result);
    return (NULL);
}

static int init_splited_t(splited_t *spl, char const *s, char const *separtrs)
{
    my_memset(spl, 0, sizeof(splited_t));
    spl->separators = separtrs;
    spl->str = s;
    spl->word_count = word_count(spl);
    if (spl->word_count < 0)
        return (0);
    spl->result = my_calloc(sizeof(char *), (spl->word_count + 1));
    if (spl->result == NULL)
        return (0);
    spl->offset = 0;
    return (1);
}

char **my_coolersplit(char const *s, char const *separators)
{
    int i = 0;
    size_t end;
    splited_t spl;

    if (!init_splited_t(&spl, s, separators))
        return (NULL);
    while (i < spl.word_count){
        spl.offset += find_next_start(&spl);
        end = find_next_end(&spl);
        spl.result[i] = malloc(sizeof(char) * (end + 1));
        if (spl.result[i] == NULL)
            return (delete_splited_t(&spl, 1));
        copy_without_quotations(spl.result[i], spl.str + spl.offset, end);
        i ++;
        spl.offset += end;
    }
    delete_splited_t(&spl, 0);
    return (spl.result);
}
