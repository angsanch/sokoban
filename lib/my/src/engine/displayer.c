/*
** EPITECH PROJECT, 2024
** displayer.c
** File description:
** Put sprites on screen
*/

#include "../../include/engine_utils.h"

static void display_sprite_texture(dn_sprite_t *sprite, sfRenderWindow *window)
{
    if (sprite->display.texture == NULL || !sprite->display.draw_texture)
        return;
    sfSprite_setPosition(sprite->sprite, sprite->center);
    sfSprite_setTexture(sprite->sprite, sprite->display.texture->texture,
        sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->display.rect);
    sfSprite_setRotation(sprite->sprite,
        sprite->angle * sprite->display.rotate_texture);
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

static void display_sprite_outline(dn_sprite_t *sprite, sfRenderWindow *window)
{
    if (sprite->display.outline == NULL || !sprite->display.draw_outline)
        return;
    sfRectangleShape_setSize(sprite->display.outline,
        sprite->display.outline_size);
    sfRectangleShape_setOrigin(sprite->display.outline, (sfVector2f){
    sprite->display.outline_size.x / 2, sprite->display.outline_size.y / 2});
    sfRectangleShape_setPosition(sprite->display.outline, sprite->center);
    sfRectangleShape_setOutlineThickness(sprite->display.outline, 1);
    sfRectangleShape_setOutlineColor(sprite->display.outline,
        sprite->display.outline_color);
    sfRectangleShape_setRotation(sprite->display.outline,
        sprite->angle * sprite->display.rotate_outline);
    sfRenderWindow_drawRectangleShape(window, sprite->display.outline, NULL);
}

static void display_sprite_circle(dn_sprite_t *sprite, sfRenderWindow *window)
{
    if (sprite->display.circle == NULL || !sprite->display.draw_circle)
        return;
    sfCircleShape_setRadius(sprite->display.circle,
        sprite->display.circle_size);
    sfCircleShape_setOrigin(sprite->display.circle, (sfVector2f){
    sprite->display.circle_size, sprite->display.circle_size});
    sfCircleShape_setPosition(sprite->display.circle, sprite->center);
    sfCircleShape_setOutlineThickness(sprite->display.circle, 1);
    sfCircleShape_setOutlineColor(sprite->display.circle,
        sprite->display.circle_color);
    sfRenderWindow_drawCircleShape(window, sprite->display.circle, NULL);
}

static void display_sprite_text(dn_sprite_t *sprite, dn_window_t *window)
{
    sfFloatRect bounds = sfText_getGlobalBounds(sprite->display.text);

    if (sprite->display.text == NULL || !sprite->display.draw_text)
        return;
    sfText_setCharacterSize(sprite->display.text, sprite->display.text_size);
    sfText_setColor(sprite->display.text, sprite->display.text_color);
    sfText_setOrigin(sprite->display.text, (sfVector2f){0, bounds.height / 2});
    sfText_setRotation(sprite->display.text,
        sprite->angle * sprite->display.rotate_text);
    sfText_setPosition(sprite->display.text, sprite->position);
    sfText_setFont(sprite->display.text, window->scene->font);
    sfRenderWindow_drawText(window->window, sprite->display.text, NULL);
}

void display_sprite(void *sprite_void, void *window_void)
{
    dn_sprite_t *sprite = sprite_void;
    dn_window_t *window = window_void;

    sprite->center = (sfVector2f){sprite->position.x - sprite->offset.x,
        sprite->position.y - sprite->offset.y};
    display_sprite_texture(sprite, window->window);
    display_sprite_outline(sprite, window->window);
    display_sprite_circle(sprite, window->window);
    display_sprite_text(sprite, window);
}
