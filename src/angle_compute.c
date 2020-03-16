/*
** EPITECH PROJECT, 2019
** angle compute
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

sfVector2f get_direction_vector(plane_t *plane)
{
    sfVector2f direction_vector;

    direction_vector.x = plane->goal.x - plane->coord.x;
    direction_vector.y = -plane->goal.y - -plane->coord.y;

    return (direction_vector);
}

float scalar_product(sfVector2f u, sfVector2f v)
{
    return (u.x * v.x + u.y * v.y);
}

float vector_norm(sfVector2f u)
{
    return ((float)sqrt(pow((double)u.x, 2) + pow((double)u.y, 2)));
}

float compute_angle(plane_t *plane)
{
    sfVector2f rep = {1, 0};
    float converse = 180 / M_PI;
    float first = scalar_product(get_direction_vector(plane), rep);
    float second = vector_norm(get_direction_vector(plane));
    float compute = first / second;
    float angle = acos(compute) * converse;
    return (get_direction_vector(plane).y >= 0 ? -angle : angle);
}

void set_vspeed(plane_t *plane)
{
    sfVector2f vector = get_direction_vector(plane);
    plane->vx = vector.x * (plane->speed / vector_norm(vector));
    plane->vy = -vector.y * (plane->speed / vector_norm(vector));
}