/*
** EPITECH PROJECT, 2019
** math
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

float mcos(float angle)
{
    double angl = (double)angle;
    double x = cos(angl);

    if ((int)(x * 10000) == 0)
        return ((float)0);
    else
        return ((float)x);
}

float msin(float angle)
{
    double angl = (double)angle;
    double x = sin(angl);

    if ((int)(x * 10000) == 0)
        return (0);
    else
        return ((float)x);
}

sfVector2f rotate_point(sfVector2f a, sfVector2f b, float angle)
{
    double converse = M_PI / 180;
    float ax = a.x - b.x;
    float ay = a.y - b.y;
    float x = ax * mcos(angle * converse) + ay * msin(angle * converse) + b.x;
    float y = -ax * msin(angle * converse) + ay * mcos(angle * converse) + b.y;

    return ((sfVector2f){x, y});
}

sfVector2f vector_decal(plane_t *plane)
{
    sfVector2f b = {plane->coord.x - plane->size / 2,
        plane->coord.y - plane->size / 2};
    sfVector2f new_b = rotate_point(b, plane->coord, plane->angle);
    sfVector2f vect = {new_b.x - plane->coord.x, new_b.y - plane->coord.y};

    return (vect);
}