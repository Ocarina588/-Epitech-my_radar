/*
** EPITECH PROJECT, 2020
** error
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int error_argument(void)
{
    my_putstr("ne rentrez qu'un argument svp: ./my_radar script\n");
    return (1);
}

int error_script(void)
{
    my_putstr("script non valide :\n");
    my_putstr("[A][espace(s)][x][espace(s)][y]");
    my_putstr("[espace(s)][x][espace(s)][y][espace(s)][vitesse][espace(s)]");
    my_putstr("[delaie][(\\n)]\n");
    my_putstr("[T][espace(s)][x][espace][y][espace][radius]\n");
    my_putstr("le script gere les nombres a vergules\n");
    return (1);
}