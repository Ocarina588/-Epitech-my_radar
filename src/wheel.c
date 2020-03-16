/*
** EPITECH PROJECT, 2020
** wheel
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

plane_t *pop_plane(plane_t **head, plane_t *plane)
{
    plane_t *tmp = *head;

    if (*head == plane) {
        *head = plane->list;
        return (plane);
    }

    while (tmp->list != plane)
        tmp = tmp->list;
    tmp->list = plane->list;

    return (plane);
}

void push_wheel(plane_t **head, plane_t *plane)
{
    plane_t *tmp = *head;

    if (!*head) {
        *head = plane;
        return;
    }
    while (tmp->wheel)
        tmp = tmp->wheel;
    tmp->wheel = plane;
}

void pop_wheel(plane_t **head, plane_t *plane)
{
    plane_t *tmp = *head;

    if (!tmp)
        return;
    if (*head == plane) {
        *head = plane->wheel;
        return;
    }

    while (tmp->wheel != plane)
        tmp = tmp->wheel;

    tmp->wheel = plane->wheel;
}

void wheel_manager(elements_t *elements, window_t *window)
{
    plane_t *tmp = elements->list;
    plane_t *to_give;

    if (window->pause)
        return;
    window->micro += window->time->dt * 1000000.0F;
    while (tmp) {
        if ((int)(tmp->delay * 1000000) <= window->micro) {
            to_give = pop_plane(&elements->list, tmp);
            push_wheel(&elements->wheel, to_give);
        }
        tmp = tmp->list;
    }
}