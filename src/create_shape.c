/*
** EPITECH PROJECT, 2019
** create shape
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void create_shape(elements_t *elements)
{
    sfRectangleShape **hitbox;
    plane_t *plane;
    for (int i = 0; i < elements->nb_plane ; i++) {
        hitbox = &elements->plane[i].hitbox;
        plane = &elements->plane[i];
        plane->size = 20;
        plane->angle = compute_angle(plane);
        plane->decal.x = vector_decal(plane).x;
        plane->decal.y = vector_decal(plane).y;
        set_vspeed(plane);
        set_points(plane);
        *hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(*hitbox, (sfVector2f){plane->size,
            plane->size});
        sfRectangleShape_setOutlineColor(*hitbox, sfWhite);
        sfRectangleShape_setOutlineThickness(*hitbox, 2);
        sfRectangleShape_setRotation(*hitbox, plane->angle + 90);
    }
    init_list(elements);
}

void create_texture_plane(elements_t *elements)
{
    plane_t *plane;

    elements->t_plane = sfTexture_createFromFile("sprites/plane.png", NULL);
    for (int i = 0; i < elements->nb_plane ; i++) {
        plane = &elements->plane[i];
        sfRectangleShape_setTexture(plane->hitbox, elements->t_plane, 1);
    }
}

void stick_hitbox(elements_t *elements)
{
    static int i = 1;
    sfRectangleShape *hitbox;

    i++;
    for (int j = 0; j < elements->nb_plane ; j++) {
        hitbox = elements->plane[j].hitbox;
        if (i % 2)
            sfRectangleShape_setOutlineThickness(hitbox, 2);
        else
            sfRectangleShape_setOutlineThickness(hitbox, 0);
    }

    elements->draw_zone = i % 2 == 1;
}

void stick_texture(elements_t *elements)
{
    static int i = 1;
    sfRectangleShape *hitbox;

    i++;
    for (int j = 0; j < elements->nb_plane ; j++) {
        hitbox = elements->plane[j].hitbox;
        if (i % 2)
            sfRectangleShape_setFillColor(hitbox, sfWhite);
        else
            sfRectangleShape_setFillColor(hitbox, sfTransparent);
    }
    elements->draw_eye = i % 2 == 1;
}

void create_zone(elements_t *elements)
{
    radar_t *radar;

    elements->draw_eye = 1;
    elements->draw_zone = 1;
    elements->t_radar = sfTexture_createFromFile("sprites/eye.png", NULL);
    for (int i = 0; i < elements->nb_radar ; i++) {
        radar = &elements->radar[i];
        radar->eye = sfSprite_create();
        radar->zone = sfCircleShape_create();
        sfCircleShape_setRadius(radar->zone, radar->radius);
        sfCircleShape_setOutlineColor(radar->zone, sfWhite);
        sfCircleShape_setFillColor(radar->zone, sfTransparent);
        sfCircleShape_setOutlineThickness(radar->zone, 2);
        sfCircleShape_setPosition(radar->zone, (sfVector2f){radar->coord.x -
            radar->radius, radar->coord.y - radar->radius});
        sfSprite_setTexture(radar->eye, elements->t_radar, 1);
        sfSprite_setScale(radar->eye, (sfVector2f){0.039, 0.039});
        sfSprite_setPosition(radar->eye, (sfVector2f){radar->coord.x - 10,
            radar->coord.y - 10});
    }
}