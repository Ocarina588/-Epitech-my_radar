/*
** EPITECH PROJECT, 2019
** read script
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char **read_script(char *str)
{
    FILE *fd = fopen(str, "r");
    size_t size = 0;
    ssize_t rep = 0;
    char **tab = NULL;
    int lines = 0;

    if (!fd)
        return (NULL);

    lines = count_lines(str);
    tab = malloc((lines + 1) * sizeof(char *));

    for (int i = 0; i < lines ; i++, size = 0) {
        tab[i] = NULL;
        getline(&tab[i], &size, fd);
    }
    tab[lines] = NULL;
    fclose(fd);
    return (tab);
}

int count_lines(char *str)
{
    FILE *fd = fopen(str, "r");
    char *buffer = NULL;
    size_t size = 0;
    ssize_t rep = 0;
    int lines = 0;

    rep = getline(&buffer, &size, fd);
    lines += (rep >= 0);
    while (rep >= 0) {
        rep = getline(&buffer, &size, fd);
        lines += (rep >= 0);
    }
    fclose(fd);
    free(buffer);
    return (lines);
}

int count_elements(char **tab, elements_t *elements)
{
    int nb_spaces = 0;
    int rep_space = 0;

    elements->nb_plane = 0;
    elements->nb_radar = 0;
    for (int i = 0; tab[i] ; i++, nb_spaces = 0, rep_space = 0) {
        if ((*tab[i] != 'A' && *tab[i] != 'T') || tab[i][1] != ' ')
            return (1);
        for (int j = 0; tab[i][j] ; j++) {
            nb_spaces += !rep_space && tab[i][j] == ' ';
            rep_space = tab[i][j] == ' ';
        }
        if (nb_spaces == 6)
            elements->nb_plane++;
        else if (nb_spaces == 3)
            elements->nb_radar++;
        else
            return (1);
    }
    return (0);
}

int fill_elements(char *str, elements_t *elements)
{
    int rep = *str == 'A';
    static int count[2] = {0};
    float *tab[2][6] = {{
        &elements->plane[count[0]].coord.x,
        &elements->plane[count[0]].coord.y,
        &elements->plane[count[0]].goal.x,
        &elements->plane[count[0]].goal.y,
        &elements->plane[count[0]].speed,
        &elements->plane[count[0]].delay}, {
        &elements->radar[count[1]].coord.x,
        &elements->radar[count[1]].coord.y,
        &elements->radar[count[1]].radius,
    }};

    rep = rep ? fill_element(str, tab[0]) : fill_element(str, tab[1]);
    count[0] += *str == 'A';
    count[1] += *str == 'T';

    return (rep);
}

elements_t *init_elements(char *str)
{
    elements_t *elements = malloc(sizeof(elements_t));
    char **tab = read_script(str);

    if (!tab || count_elements(tab, elements))
        return (NULL);
    elements->plane = malloc(elements->nb_plane * sizeof(plane_t));
    elements->radar = malloc(elements->nb_radar * sizeof(radar_t));
    for (int i = 0; tab[i] ; i++) {
        if (fill_elements(tab[i], elements))
            return (NULL);
        free(tab[i]);
    }
    if (!*tab)
        return (NULL);
    else {
        create_shape(elements);
        create_texture_plane(elements);
        create_zone(elements);
    }
    free(tab);
    return (elements);
}