/*
** EPITECH PROJECT, 2023
** basic_list.c
** File description:
** Basic utils
*/

#include <stdlib.h>
#include "../../include/my.h"

l_elem *create_elem(void *content)
{
    l_elem *e = malloc(sizeof(l_elem) * 1);

    if (e == NULL)
        return (NULL);
    e->next = NULL;
    e->content = content;
    return (e);
}

void destroy_elem(l_elem *e, void(*del)(void *))
{
    if (e == NULL)
        return;
    (*del)(e->content);
    free(e);
}

l_elem *list_last_element(l_list *l)
{
    l_elem *e = l->first;

    if (e == NULL)
        return (NULL);
    while (e->next != NULL)
        e = e->next;
    return (e);
}

l_list *list_destroy(l_list *l)
{
    size_t i = 0;
    l_elem *current;

    if (l == NULL)
        return (NULL);
    if (l->first == NULL){
        free(l);
        return (NULL);
    }
    while (i < l->len){
        current = l->first;
        l->first = l->first->next;
        destroy_elem(current, l->del);
        i ++;
    }
    free(l);
    return (NULL);
}

l_list *list_create(void(*del)(void *))
{
    l_list *l = malloc(sizeof(l_list) * 1);

    if (l == NULL)
        return (NULL);
    l->len = 0;
    l->first = NULL;
    l->del = del;
    return (l);
}
