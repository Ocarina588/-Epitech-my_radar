/*
** EPITECH PROJECT, 2019
** window management
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

window_t *init_window(void)
{
    window_t *window = malloc(sizeof(window_t));
    window->draw_quad_tree = 1;
    window->mode.bitsPerPixel = 32;
    window->mode.height = 1080;
    window->mode.width = 1920;
    window->pause = 0;
    window->micro = 0;
    window->info = 1;
    window->background = sfSprite_create();
    window->t_backround = sfTexture_createFromFile("sprites/map.jpg", NULL);
    window->time = init_time();
    sfSprite_setTexture(window->background, window->t_backround, 1);
    sfSprite_setScale(window->background, (sfVector2f){0.46, 0.46});
    window->render = sfRenderWindow_create(window->mode, "my radar",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window->render, 120);
    return (window);
}

void my_radar_mangement(elements_t *elements,
    window_t *window, qt_t *qt, ui_t *ui)
{
    sfRenderWindow_clear(window->render, sfWhite);
    while (sfRenderWindow_pollEvent(window->render, &window->event))
        event_manager(elements, window);
    sfRenderWindow_drawSprite(window->render, window->background, NULL);
    draw_manager(window, elements, qt, ui);
    sfRenderWindow_display(window->render);
}

void draw_plane(window_t *window, elements_t *elements)
{
    plane_t *tmp = elements->wheel;

    while (tmp) {
        if (!is_goal(*tmp) && !tmp->destroyed) {
        sfRectangleShape_setPosition(tmp->hitbox,
            move_points(tmp, window));
        sfRenderWindow_drawRectangleShape(window->render,
            tmp->hitbox, NULL);
        } else
            pop_wheel(&elements->wheel, tmp);
        tmp = tmp->wheel;
    }
    if (!elements->wheel && !elements->list)
        sfRenderWindow_close(window->render);
}

void draw_radar(window_t *window, elements_t *elements)
{
    for (int i = 0; elements->draw_zone && i < elements->nb_radar ; i++)
        sfRenderWindow_drawCircleShape(window->render,
            elements->radar[i].zone, NULL);
    for (int i = 0; elements->draw_eye && i < elements->nb_radar ; i++)
        sfRenderWindow_drawSprite(window->render,
            elements->radar[i].eye, NULL);
}

void draw_manager(window_t *window,
    elements_t *elements, qt_t *quad_tree, ui_t *ui)
{
    draw_radar(window, elements);
    draw_plane(window, elements);
    if (window->draw_quad_tree)
        draw_quad_tree(quad_tree, window);
    draw_ui(ui, window, elements);
}