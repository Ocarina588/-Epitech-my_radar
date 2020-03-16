/*
** EPITECH PROJECT, 2020
** ui
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

ui_t *init_ui(void)
{
    ui_t *ui = malloc(sizeof(ui_t));
    ui->fps = new_text("", 0, 0, sfYellow);
    ui->timer = new_text("", 1890, 0, sfYellow);
    ui->sprites = new_text("Sprites (S):", 1200, 0, sfYellow);
    ui->shape = new_text("Shapes (L):", 800, 0, sfYellow);
    ui->quad_tree = new_text("Quad Tree (Q):", 350, 0, sfYellow);
    ui->on = new_text("ON", 500, 500, sfGreen);
    ui->off = new_text("OFF", 500, 550, sfRed);
    init_background_pause(ui);
    init_pause(ui);

    return (ui);
}

void draw_text(sfText *text, window_t *window, sfVector2f vect)
{
    sfText_setPosition(text, vect);
    sfRenderWindow_drawText(window->render, text, NULL);
}

void draw_ui(ui_t *ui, window_t *window, elements_t *elements)
{
    if (window->info)
        text_manager(window, ui, elements);
    draw_pause(ui, window);
}