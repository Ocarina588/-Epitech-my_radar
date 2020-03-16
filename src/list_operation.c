/*
** EPITECH PROJECT, 2019
** list operation
** File description:
** sfd
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int len_list(plane_t *head)
{
    int len = 0;

    while (head) {
        len++;
        head = head->next;
    }

    return (len);
}

void push(qt_t *quad_tree, plane_t *plane)
{
    plane_t *tmp = quad_tree->plane_head;
    int i = 0;

    if (tmp) {
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = plane;
    } else
        quad_tree->plane_head = plane;
}

void init_list(elements_t *elements)
{
    plane_t *tmp;
    elements->list = &elements->plane[0];
    elements->wheel = NULL;
    tmp = elements->list;
    for (int i = 0; i < elements->nb_plane ; i++) {
        elements->plane[i].wheel = NULL;
        elements->plane[i].list = NULL;
        elements->plane[i].next = NULL;
        elements->plane[i].destroyed = 0;
        if (i) {
            tmp->list = &elements->plane[i];
            tmp = tmp->list;
        }
    }
}