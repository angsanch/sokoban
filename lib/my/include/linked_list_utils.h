/*
** EPITECH PROJECT, 2023
** linked_lists_utils.h
** File description:
** Linked list utils
*/

#ifndef LINKED_LIST_UTILS_H_
    #define LINKED_LIST_UTILS_H_

    #include <stdlib.h>
    #include "linked_list.h"

void initialize_elem(l_elem_t *e, void *content);
l_elem_t *create_elem(void *content);
void delete_elem(l_elem_t *e, void(*del)(void *));
void destroy_elem(l_elem_t *e, void(*del)(void *));
void destroy_list(l_list_t *l);
l_elem_t *list_get_last(l_list_t *l);
l_elem_t *list_get_index_elem(l_list_t *l, size_t index);
l_list_t *create_list(void(*del)(void *));
size_t list_len(l_list_t *l);

#endif
