/*
** EPITECH PROJECT, 2023
** simple_operations.c
** File description:
** Simple operations to the list
*/

#include "../../include/linked_list_utils.h"

size_t list_len(l_list_t *l)
{
    l_elem_t *e = l->first;
    size_t i = 0;

    while (e != NULL)
        e = e->next;
    return (i);
}

l_elem_t *list_get_last(l_list_t *l)
{
    l_elem_t *e = l->first;

    if (e == NULL)
        return (NULL);
    while (e->next != NULL)
        e = e->next;
    return (e);
}

void list_pop_first(l_list_t *l)
{
    l_elem_t *e = l->first;

    l->first = e->next;
    destroy_elem(e, l->del);
    l->len --;
}

l_elem_t *list_get_index_elem(l_list_t *l, size_t index)
{
    l_elem_t *e = l->first;
    size_t i = 0;

    while (e != NULL && i < index){
        i ++;
        e = e->next;
    }
    return (e);
}

void *list_get_index(l_list_t *l, size_t index)
{
    l_elem_t *e = list_get_index_elem(l, index);

    if (e == NULL)
        return (NULL);
    else
        return (e->content);
}
