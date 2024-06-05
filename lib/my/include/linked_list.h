/*
** EPITECH PROJECT, 2024
** linked_lists.h
** File description:
** linked lists for external use
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include <stdlib.h>
    #include <unistd.h>

typedef struct linked_list_element {
    void *content;
    struct linked_list_element *next;
} l_elem_t;

typedef struct linked_list_container {
    size_t len;
    l_elem_t *first;
    void(*del)(void *);
} l_list_t;

void list_delete(l_list_t *l);
l_list_t *list_destroy(l_list_t *l);
void list_initialize(l_list_t *l, void(*del)(void *));
l_list_t *list_create(void(*del)(void *));
size_t list_len(l_list_t *l);
int list_push(l_list_t *l, void *content);
int list_append(l_list_t *l, void *content);
int list_insert(l_list_t *l, size_t index, void *content);
int list_pop(l_list_t *l, size_t index);
void *list_get_index(l_list_t *l, size_t index);
void list_import(l_list_t *l, void **data);
void **list_export(l_list_t *l, void *(*transform)(void *));
void list_unlink(l_list_t *l);
void list_pop_first(l_list_t *l);
void list_iter(l_list_t *l, void(*func)(void *, void *), void *data);
ssize_t list_first_fulfil(l_list_t *l, int(*func)(void *, void *), void *data);
size_t list_count_fulfil(l_list_t *l, int(*func)(void *, void *), void *data);
int list_sort(l_list_t *l, int(*comp)(void *, void *));

#endif
