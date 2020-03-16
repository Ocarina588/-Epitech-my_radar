/*
** EPITECH PROJECT, 2019
** event manager
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void event_manager(elements_t *elements, window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->render);
    if (window->event.type == sfEvtKeyPressed) {
        if (window->event.key.code == (sfKeyI))
            window->info = ++window->info % 2;
        if (window->event.key.code == (sfKeyEscape))
            window->pause = ++window->pause % 2;
        if (window->event.key.code == (sfKeyL))
            stick_hitbox(elements);
        if (window->event.key.code == (sfKeyS))
            stick_texture(elements);
        if (window->event.key.code == (sfKeyQ))
            window->draw_quad_tree = ++window->draw_quad_tree % 2;
    }
}