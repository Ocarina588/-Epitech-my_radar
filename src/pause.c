/*
** EPITECH PROJECT, 2020
** pause
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void init_background_pause(ui_t *ui)
{
    ui->background_pause = sfSprite_create();
    ui->t_background_pause = sfTexture_createFromFile("sprites/gray.png",
        NULL);
    sfSprite_setTexture(ui->background_pause, ui->t_background_pause, 1);
    sfSprite_setPosition(ui->background_pause, (sfVector2f){0, 0});
    sfSprite_setScale(ui->background_pause, (sfVector2f){2, 2});
}

void init_pause(ui_t *ui)
{
    ui->pause = sfSprite_create();
    ui->t_pause = sfTexture_createFromFile("sprites/pause.png",
        NULL);
    sfTexture_setSmooth(ui->t_pause, 1);
    sfSprite_setTexture(ui->pause, ui->t_pause, 1);
    sfSprite_setPosition(ui->pause, (sfVector2f){650, 350});
    sfSprite_setScale(ui->pause, (sfVector2f){3, 3});
}

void draw_pause(ui_t *ui, window_t *window)
{
    static float rep = 0;
    if (!window->pause)
        return;
    sfColor color = sfSprite_getColor(ui->pause);
    color.a = (int)((cosf(rep) + 1) / 2);
    sfSprite_setColor(ui->pause, color);
    sfRenderWindow_drawSprite(window->render, ui->background_pause, NULL);
    sfRenderWindow_drawSprite(window->render, ui->pause, NULL);
    rep += 0.05;
}