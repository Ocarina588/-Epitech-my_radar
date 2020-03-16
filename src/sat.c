/*
** EPITECH PROJECT, 2020
** sat
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int colide_plane(plane_t *a, plane_t *b)
{
    float len = sqrtf(powf(b->coord.x - a->coord.x, 2)
        + powf(b->coord.y - a->coord.y, 2));
    return (len <= 28 ? 1 : 0);
}

int colide_radar(plane_t *a, plane_t *b, elements_t *elements)
{
    float len;
    float lenbis;
    radar_t *radar;

    for (int i = 0; i < elements->nb_radar ; i++) {
        radar = &elements->radar[i];
        len = sqrtf(powf(radar->coord.x - a->coord.x, 2)
        + powf(radar->coord.y - a->coord.y, 2));
        lenbis = sqrtf(powf(radar->coord.x - b->coord.x, 2)
        + powf(radar->coord.y - b->coord.y, 2));

        if (len < radar->radius && lenbis < radar->radius)
            return (1);
    }

    return (0);
}

void destroy(elements_t *elements, qt_t *quad_tree)
{
    plane_t *tmp = elements->wheel;

    while (tmp) {
        if (!tmp->destroyed)
            find_colide(tmp, quad_tree, elements);
        tmp = tmp->wheel;
    }
}

