/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <unistd.h>

typedef struct linked_list_element{
    void *content;
    struct linked_list_element *next;
} l_elem;

typedef struct linked_list_container{
    size_t len;
    l_elem *first;
    void(*del)(void *);
} l_list;

char *convert_base(char const *nbr,
    char const *base_from, char const *base_to);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_intlen_base(int nb, int base_len);
int my_getnbr_base(char const *str, char const *base);
int my_intlen(int nb);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
int my_memcmp(const void *s1, const void *s2, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *b, int c, size_t len);
void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);
void my_put_nbr(int nb);
size_t my_putstr(char const *str);
void swap_chr(char *a, char *b);
char *my_revstr(char *str);
void my_showmem(char const *str, size_t size);
void my_showstr(char const *str);
void my_show_word_array(char *const *tab);
void my_sort_int_array(int *array, size_t size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
ssize_t my_strchr_index(char const *str, char c);
size_t my_strchr_count(char const *str, char c);
char *my_strchr(char const *str, char c);
char *my_strrchr(char const *str, char c);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_isalpha(char c);
int my_str_isalpha(char const *str);
int my_islower(char c);
int my_str_islower(char const *str);
int my_isnumeric(char c);
int my_str_isnum(char const *str);
int my_isprintable(char c);
int my_str_isprintable(char const *str);
int my_isupper(char c);
int my_str_isupper(char const *str);
size_t my_strlen(char const *str);
void my_to_lower(char *chr);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, size_t nb);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncpy(char *dest, char const *src, size_t n);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str);
void my_to_upper(char *chr);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

int my_printf(char const *format, ...);

l_list *list_destroy(l_list *l);
l_list *list_create(void(*del)(void *));
size_t list_len(l_list *l);
int list_append(l_list *l, void *content);
void **list_export(l_list *l);
void list_pop_first(l_list *l);

#endif
