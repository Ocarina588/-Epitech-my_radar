/*
** EPITECH PROJECT, 2020
** text
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *nb_to_str(int nb)
{
    char one[nb_len(nb) + 1];
    static char two[10];
    int tmp = nb;

    for (int i = 0; i < nb_len(nb) ; i++) {
        one[i] = tmp % 10;
        tmp /= 10;
    }
    for (int i = 0, j = nb_len(nb) - 1; i < nb_len(nb) ; i++, j--)
        two[i] = one[j] + '0';
    two[nb_len(nb)] = 0;
    return (two);
}

void update_fps(ui_t *ui, window_t *window)
{
    int nb = (int)window->micro / 1000000;
    sfVector2f vect = sfText_getPosition(ui->timer->text);
    vect.x = 1890 - 25 * (nb_len(nb) - 1);
    sfText_setString(ui->fps->text, nb_to_str(window->time->fps));
    sfText_setPosition(ui->timer->text, vect);
    sfText_setString(ui->timer->text, nb_to_str(nb));
}

void text_manager(window_t *window, ui_t *ui, elements_t *elements)
{
    update_fps(ui, window);
    sfVector2f vect;
    float rep = sfRectangleShape_getOutlineThickness(elements->plane[0].hitbox);
    sfColor color = sfRectangleShape_getFillColor(elements->plane[0].hitbox);
    vect = sfText_getPosition(ui->shape->text);
    vect.x += 280;
    draw_text(rep ? ui->on->text : ui->off->text, window, vect);
    vect = sfText_getPosition(ui->sprites->text);
    vect.x += 300;
    draw_text(color.a ? ui->on->text : ui->off->text, window, vect);
    vect = sfText_getPosition(ui->quad_tree->text);
    vect.x += 350;
    draw_text(window->draw_quad_tree ?
        ui->on->text : ui->off->text, window, vect);
    sfRenderWindow_drawText(window->render, ui->fps->text, NULL);
    sfRenderWindow_drawText(window->render, ui->timer->text, NULL);
    sfRenderWindow_drawText(window->render, ui->shape->text, NULL);
    sfRenderWindow_drawText(window->render, ui->sprites->text, NULL);
    sfRenderWindow_drawText(window->render, ui->quad_tree->text, NULL);
}

text_t *init_text(char *font)
{
    text_t *text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile(font);
    text->text = sfText_create();
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, "0");
    sfText_setColor(text->text, sfYellow);
    sfText_setOutlineThickness(text->text, 3);
    sfText_setPosition(text->text, (sfVector2f){0, 0});
    sfText_setOutlineColor(text->text, sfBlack);
    sfText_setCharacterSize(text->text, 40);

    return (text);
}

text_t *new_text(char *str, float x, float y, sfColor color)
{
    text_t *text = init_text("sprites/font.ttf");
    sfText_setColor(text->text, color);
    sfText_setString(text->text, str);
    sfText_setPosition(text->text, (sfVector2f){x, y});
    return (text);
}