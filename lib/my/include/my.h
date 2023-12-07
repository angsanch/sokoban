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
    #include "structs.h"

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
int my_sprintf(char *str, char const *format, ...);
int my_dprintf(int fd, char const *format, ...);

l_list *list_destroy(l_list *l);
l_list *list_create(void(*del)(void *));
size_t list_len(l_list *l);
int list_append(l_list *l, void *content);
void **list_export(l_list *l);
void list_pop_first(l_list *l);
void list_iter(l_list *l, void(*func)(void *));
void list_iter_data(l_list *l, void *data, void(*func)(void *, void *));

dn_sound *search_sound(dn_scene *scene, size_t id);
dn_texture *search_texture(dn_scene *scene, size_t id);
dn_sprite *search_sprite(dn_scene *scene, size_t id);
dn_scene *search_scene(dn_window *window, size_t id);
dn_scene *create_scene(dn_window *window);
void add_sprite(dn_scene *scene);
void add_texture(dn_scene *scene, dn_texture *texture);
void add_functions(dn_scene *scene,
    void(*tick)(struct dn_sprite_container *, dn_envinfo *),
    void(*event)(struct dn_sprite_container *, dn_envinfo *));
void add_push_sprite(dn_scene *scene);
void add_data(dn_scene *scene, void *data, void(*destroy_data)(void *));
void sprite_link_texture(dn_sprite *sprite, dn_texture *texture);
void sprite_add_data(dn_sprite *sprite, void *data,
    void(*destroy_data)(void *));
void sprite_set_rect(dn_sprite *sprite, size_t x, size_t y);
int is_on_sprite(dn_window *window, dn_sprite *sprite, int x, int y);
dn_texture *create_texture(dn_scene *scene, char const *path,
    size_t x_tiles, size_t y_tiles);
dn_sprite *create_sprite(dn_scene *scene);
dn_window *create_window(int width, int height, char *name, sfUint32 style);
void destroy_window(dn_window *window);
int tick_window(dn_window *window);
dn_fps *create_fps_limiter(float max);
void next_frame(dn_fps *fps);
void destroy_fps_limiter(dn_fps *fps);

#endif
