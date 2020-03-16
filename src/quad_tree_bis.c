/*
** EPITECH PROJECT, 2019
** quad tree bis
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void insert_manager(elements_t *elements, qt_t *quad_tree)
{
    plane_t *tmp = elements->wheel;

    for (int i = 0; i < elements->nb_plane ; i++)
        elements->plane[i].next = NULL;

    while (tmp) {
        insert(tmp, quad_tree);
        tmp = tmp->wheel;
    }
}

int insert(plane_t *plane, qt_t *quad_tree)
{
    if (!colide_quad_tree(plane, quad_tree))
        return (0);
    if (len_list(quad_tree->plane_head) < quad_tree->capacity) {
        push(quad_tree, plane);
        return (1);
    }
    else {
        if (!quad_tree->is_divided)
            subdivide(quad_tree);
        if (insert(plane, quad_tree->ne))
            return (1);
        if (insert(plane, quad_tree->nw))
            return (1);
        if (insert(plane, quad_tree->se))
            return (1);
        if (insert(plane, quad_tree->sw))
            return (1);
    }
}

int colide_quad_tree(plane_t *plane, qt_t *quad_tree)
{
    sfVector2f vector = {plane->points.sw.x - plane->points.ne.x,
                        plane->points.sw.y - plane->points.ne.y};
    sfVector2f point = get_colid_point_circle(plane, quad_tree);
    sfVector2f u = {point.x - plane->coord.x, point.y - plane->coord.y};
    float radius = vector_norm(vector) / 2;

    if (vector_norm(u) < radius)
        return (1);

    return (0);
}

sfVector2f get_colid_point_circle(plane_t *plane, qt_t *quad_tree)
{
    sfVector2f point;

    if (plane->coord.x <= quad_tree->inf.x)
        point.x = quad_tree->inf.x;
    else if (plane->coord.x >= quad_tree->inf.x + quad_tree->inf.w)
        point.x = quad_tree->inf.x + quad_tree->inf.w;
    else
        point.x = plane->coord.x;

    if (plane->coord.y <= quad_tree->inf.y)
        point.y = quad_tree->inf.y;
    else if (plane->coord.y >= quad_tree->inf.y + quad_tree->inf.h)
        point.y = quad_tree->inf.y + quad_tree->inf.h;
    else
        point.y = plane->coord.y;

    return (point);
}

void find_colide(plane_t *plane, qt_t *quad_tree, elements_t *elements)
{
    plane_t *tmp = quad_tree->plane_head;

    if (!colide_quad_tree(plane, quad_tree))
        return;

    while (tmp) {
        if (tmp != plane && colide_plane(plane, tmp)
            && !colide_radar(plane, tmp, elements)) {
            plane->destroyed = 1;
            tmp->destroyed = 1;
        }
        tmp = tmp->next;
    }
    if (quad_tree->is_divided) {
        find_colide(plane, quad_tree->ne, elements);
        find_colide(plane, quad_tree->nw, elements);
        find_colide(plane, quad_tree->se, elements);
        find_colide(plane, quad_tree->sw, elements);
    }
}