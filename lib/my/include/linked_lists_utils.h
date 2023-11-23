/*
** EPITECH PROJECT, 2023
** linked_lists_utils.h
** File description:
** Linked list utils
*/

#ifndef LINKED_LISTS_UTILS_H_
    #define LINKED_LISTS_UTILS_H_

    #include <stdlib.h>
    #include "my.h"

l_elem *create_elem(void *content);
void destroy_elem(l_elem *e, void(*del)(void *));
void destroy_list(l_list *l);
l_list *create_list(void(*del)(void *));
size_t list_len(l_list *l);

#endif
