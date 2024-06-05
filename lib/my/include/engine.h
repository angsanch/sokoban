/*
** EPITECH PROJECT, 2024
** engine.h
** File description:
** engine for external use
*/
#ifndef ENGINE_H_
    #define ENGINE_H_

    #include "linked_list.h"
    #include "basic.h"
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct dn_collision_sprites dn_coll_sprites_t;

typedef struct dn_texture_t_container {
    char *id;
    sfTexture *texture;
    size_t x_tiles;
    size_t y_tiles;
} dn_texture_t;
typedef struct dn_scene_t_container {
    l_list_t *sprites;
    l_list_t *textures;
    sfMusic *music;
    sfFont *font;
    size_t id_sprite;
    char *id;
    void *creation;
} dn_scene_t;
typedef struct dn_window_t_container {
    sfRenderWindow *window;
    sfClock *clock;
    dn_scene_t *scene;
    l_list_t *scenes;
    sfVector2i resolution;
    sfVector2i size;
    void(*manage_collision)(dn_coll_sprites_t *,
        struct dn_window_t_container *);
    bool to_be_closed;
} dn_window_t;
typedef struct dn_environment_info {
    float time_delta;
    dn_window_t *window;
    sfEvent *event;
}dn_envinfo_t;
typedef struct dn_sprite_t_display_info {
    int rotate_texture;
    int rotate_outline;
    int rotate_text;
    dn_texture_t *texture;
    sfIntRect rect;
    bool draw_texture;
    sfRectangleShape *outline;
    sfColor outline_color;
    sfVector2f outline_size;
    bool draw_outline;
    sfCircleShape *circle;
    sfColor circle_color;
    float circle_size;
    bool draw_circle;
    sfText *text;
    sfColor text_color;
    int text_size;
    bool draw_text;
} dn_display_info_t;
typedef struct dn_sprite_t_container {
    size_t id;
    sfSprite *sprite;
    float angle;
    sfVector2f position;
    sfVector2f offset;
    sfVector2f center;
    dn_display_info_t display;
    void(*tick)(struct dn_sprite_t_container *, dn_envinfo_t *);
    void(*event)(struct dn_sprite_t_container *, dn_envinfo_t *);
    void(*destroy_data)(void *);
    bool collision;
    void *data;
} dn_sprite_t;
struct dn_collision_sprites {
    size_t id1;
    size_t id2;
};

dn_texture_t *search_texture(dn_scene_t *scene, char *id);
dn_sprite_t *search_sprite(dn_scene_t *scene, size_t id);
int focus_scene(dn_window_t *window, char *id);
dn_scene_t *create_scene(char const *id);
void add_sprite(dn_scene_t *scene, float x, float y);
void add_sprite_set_graphics(dn_scene_t *scene, char *texture_id,
    void(*config)(dn_sprite_t *));
void add_sprite_set_functions(dn_scene_t *scene,
    void(*tick)(struct dn_sprite_t_container *, dn_envinfo_t *),
    void(*event)(struct dn_sprite_t_container *, dn_envinfo_t *));
void add_sprite_set_text(dn_scene_t *scene, char *text);
void add_sprite_set_text_style(dn_scene_t *scene, sfColor color, size_t size);
void sprite_set_text(dn_sprite_t *sprite, char *str);
void add_push_sprite(dn_scene_t *scene);
void add_sprite_set_data(dn_scene_t *scene, void *data,
    void(*destroy_data)(void *));
void create_button(dn_scene_t *scene, char *text, sfVector2f pos);
void sprite_link_texture(dn_sprite_t *sprite, dn_texture_t *texture);
void sprite_add_data(dn_sprite_t *sprite, void *data,
    void(*destroy_data)(void *));
void sprite_set_rect(dn_sprite_t *sprite, size_t x, size_t y);
int is_on_sprite(dn_window_t *window, dn_sprite_t *sprite, int x, int y);
dn_texture_t *create_texture(dn_scene_t *scene, char const *path,
    size_t x_tiles, size_t y_tiles);
dn_sprite_t *create_sprite(dn_scene_t *scene);
int delete_sprite_by_id(dn_scene_t *scene, size_t id);
dn_window_t *create_window(int width, int height, char *name, sfUint32 style);
void destroy_window(dn_window_t *window);
int tick_window(dn_window_t *window);
void display_sprite(void *sprite_void, void *window_void);
void limit_fps(dn_window_t *window, unsigned int limit);
void window_collisions(dn_window_t *window,
    void (*manage)(dn_coll_sprites_t *, dn_window_t *));

#endif
