/*
** EPITECH PROJECT, 2019
** separate axis theoreme
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void set_points(plane_t *plane)
{
    plane->points.ne.x = plane->coord.x - plane->size / 2;
    plane->points.ne.y = plane->coord.y - plane->size / 2;

    plane->points.nw.x = plane->coord.x + plane->size / 2;
    plane->points.nw.y = plane->coord.y - plane->size / 2;

    plane->points.se.x = plane->coord.x - plane->size / 2;
    plane->points.se.y = plane->coord.y + plane->size / 2;

    plane->points.sw.x = plane->coord.x + plane->size / 2;
    plane->points.sw.y = plane->coord.y + plane->size / 2;

    plane->points.ne =
        rotate_point(plane->points.ne, plane->coord, -plane->angle - 90);
    plane->points.nw =
        rotate_point(plane->points.nw, plane->coord, -plane->angle - 90);
    plane->points.se =
        rotate_point(plane->points.se, plane->coord, -plane->angle - 90);
    plane->points.sw =
        rotate_point(plane->points.sw, plane->coord, -plane->angle - 90);
}

sfVector2f move_points(plane_t *plane, window_t *window)
{
    sfVector2f vector;
    if (!window->pause) {
        plane->coord.x += plane->vx * 40 * window->time->dt;
        plane->coord.y += plane->vy * 40 * window->time->dt;

        plane->points.ne.x += plane->vx * 40 * window->time->dt;
        plane->points.ne.y += plane->vy * 40 * window->time->dt;

        plane->points.nw.x += plane->vx * 40 * window->time->dt;
        plane->points.nw.y += plane->vy * 40 * window->time->dt;

        plane->points.se.x += plane->vx * 40 * window->time->dt;
        plane->points.se.y += plane->vy * 40 * window->time->dt;

        plane->points.sw.x += plane->vx * 40 * window->time->dt;
        plane->points.sw.y += plane->vy * 40 * window->time->dt;
    }
    vector.x = plane->coord.x - plane->decal.x;
    vector.y = plane->coord.y - -plane->decal.y;
    return (vector);
}