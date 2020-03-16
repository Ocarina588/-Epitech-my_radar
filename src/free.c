/*
** EPITECH PROJECT, 2019
** free
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void free_manager(elements_t *elements, window_t *window)
{
    sfRenderWindow_destroy(window->render);
    for (int i = 0; i < elements->nb_plane ; i++)
        sfRectangleShape_destroy(elements->plane[i].hitbox);
    for (int i = 0; i < elements->nb_radar ; i++) {
        sfSprite_destroy(elements->radar[i].eye);
    }
    sfTexture_destroy(elements->t_radar);
    sfTexture_destroy(elements->t_plane);
    sfTexture_destroy(window->t_backround);
    sfSprite_destroy(window->background);
    free(window);
    free(elements->plane);
    free(elements->radar);
    free(elements);
}

void free_quad_tree(qt_t *quad_tree)
{
    if (quad_tree->is_divided) {
        free_quad_tree(quad_tree->ne);
        free_quad_tree(quad_tree->nw);
        free_quad_tree(quad_tree->se);
        free_quad_tree(quad_tree->sw);
    }
    sfRectangleShape_destroy(quad_tree->boundary);
    free(quad_tree);
}