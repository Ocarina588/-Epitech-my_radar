/*
** EPITECH PROJECT, 2019
** quad tree
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

qt_t *new_quad_tree(sfRectangleShape *boundary)
{
    qt_t *quad_tree = malloc(sizeof(qt_t));

    quad_tree->inf = get_info(boundary);
    quad_tree->capacity = 2;
    quad_tree->is_divided = 0;
    quad_tree->boundary = boundary;
    quad_tree->plane_head = NULL;

    return (quad_tree);
}

sfRectangleShape *new_rec(float x, float y, float w, float h)
{
    sfRectangleShape *rec = sfRectangleShape_create();
    sfRectangleShape_setSize(rec, (sfVector2f){w, h});
    sfRectangleShape_setPosition(rec, (sfVector2f){x, y});
    sfRectangleShape_setFillColor(rec, sfTransparent);
    sfRectangleShape_setOutlineThickness(rec, 1);
    sfRectangleShape_setOutlineColor(rec, sfWhite);

    return (rec);
}

info_t get_info(sfRectangleShape *rec)
{
    info_t inf;

    inf.x = sfRectangleShape_getPosition(rec).x;
    inf.y = sfRectangleShape_getPosition(rec).y;
    inf.w = sfRectangleShape_getSize(rec).x;
    inf.h = sfRectangleShape_getSize(rec).y;

    return (inf);
}

void subdivide(qt_t *quad_tree)
{
    float w = quad_tree->inf.w / 2;
    float h = quad_tree->inf.h / 2;
    float x = quad_tree->inf.x;
    float y = quad_tree->inf.y;

    quad_tree->is_divided = 1;
    quad_tree->ne = new_quad_tree(new_rec(x, y, w, h));
    quad_tree->nw = new_quad_tree(new_rec(x + w, y, w, h));
    quad_tree->se = new_quad_tree(new_rec(x, y + h, w, h));
    quad_tree->sw = new_quad_tree(new_rec(x + w, y + h, w, h));
}

void draw_quad_tree(qt_t *quad_tree, window_t *window)
{
    sfRenderWindow_drawRectangleShape(window->render,
        quad_tree->boundary, NULL);

    if (quad_tree->is_divided) {
        draw_quad_tree(quad_tree->ne, window);
        draw_quad_tree(quad_tree->nw, window);
        draw_quad_tree(quad_tree->se, window);
        draw_quad_tree(quad_tree->sw, window);
    }
}