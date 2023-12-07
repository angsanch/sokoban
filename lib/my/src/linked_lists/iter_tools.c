/*
** EPITECH PROJECT, 2023
** iter_tools.c
** File description:
** Iterating the list
*/

#include "../../include/linked_lists_utils.h"

void **list_export(l_list *l)
{
    void **export;
    size_t i = 0;
    l_elem *e;

    if (l->len == 0)
        return (NULL);
    export = malloc(sizeof(char *) * l->len);
    if (export == NULL)
        return (NULL);
    e = l->first;
    while (i < l->len){
        export[i] = e->content;
        e = e->next;
        i ++;
    }
    return (export);
}

void list_iter(l_list *l, void(*func)(void *))
{
    l_elem *e = l->first;

    while (e != NULL){
        (*func)(e->content);
        e = e->next;
    }
}

void list_iter_data(l_list *l, void *data, void(*func)(void *, void *))
{
    l_elem *e = l->first;

    while (e != NULL){
        (*func)(e->content, data);
        e = e->next;
    }
}
