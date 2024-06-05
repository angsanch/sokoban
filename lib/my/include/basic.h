/*
** EPITECH PROJECT, 2024
** basic.h
** File description:
** basics for external use
*/

#ifndef BASIC_H_
    #define BASIC_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdbool.h>

char *convert_base(char const *nbr,
    char const *base_from, char const *base_to);
char *get_next_line(int fd);
void *my_calloc(size_t count, size_t size);
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
int my_memchr_index(const void *m, int c, int len);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memjoin(const void *m1, size_t s1, const void *m2, size_t s2);
void *my_memmove(void *dst, const void *src, size_t n);
void *my_memset(void *b, int c, size_t len);
void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);
void my_put_nbr(int nb);
size_t my_putstr(char const *str);
void swap_chr(char *a, char *b);
void my_revmem(void *str, size_t size);
char *my_revstr(char *str);
void my_showmem(char const *str, size_t size);
void my_showstr(char const *str);
void my_show_word_array(char *const *tab);
void my_sort_int_array(int *array, size_t size);
char **free_string_array(char **result);
size_t get_pointer_array_len(void *arr_in);
char **my_split(char const *s, char c);
char **my_coolersplit(char const *s, char const *separators);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
ssize_t my_strchr_index(char const *str, char c);
size_t my_strchr_count(char const *str, char c);
char *my_strchr(char const *str, char c);
char *my_strrchr(char const *str, char c);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strjoin(char *s1, char *s2);
char *my_coolerstrjoin(size_t n, ...);
int my_isalpha(char c);
int my_str_isalpha(char const *str);
int my_islower(char c);
int my_str_islower(char const *str);
int my_isnumeric(char c);
int my_str_isnum(char const *str);
int my_isprintable(char c);
int my_str_isprintable(char const *str);
int my_isupper(char c);
int my_str_isupper(char const *stri);
int my_isalnum(char c);
int my_str_isalnum(char const *str);
size_t my_strlen(char const *str);
void my_to_lower(char *chr);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, size_t nb);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncpy(char *dest, char const *src, size_t n);
char *my_strreplace(char *base, char *key, char *replace);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str);
void my_to_upper(char *chr);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int report_error(char *str, int response);

#endif
