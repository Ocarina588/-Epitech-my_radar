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

int check_bad_char(char c)
{
    return ((c < '0' || c > '9') && c != ' ' && c != '.'
        && c != '\n' && c != '+' && c != '-');
}

int check_con(char c, int rep_num, int rep_sign, int point)
{
    if ((rep_num && (c == '-' || c == '+')) ||
        (rep_sign && !rep_num && c == ' '))
        return (1);
    if (check_bad_char(c) || point > 1)
        return (1);
    return (0);
}

int fill_element(char *str, float **tab)
{
    int rep_sign = 0;
    int rep_num = 0;
    int point = 0;
    int count = 0;
    for (int i = 1; str[i] ; i++) {
        if (str[i - 1] == ' ')
            point = 0;
        if (str[i - 1] == ' ' && str[i] != ' ')
            *(tab[count++]) = getfloat(str + i);
        point += str[i] == '.';
        rep_sign += str[i] == '-' || str[i] == '+';
        rep_num += str[i] >= '0' && str[i] <= '9';
        if (check_con(str[i], rep_num, rep_sign, point))
            return (1);
        if (str[i] == ' ') {
            rep_sign = 0;
            rep_num = 0;
        }
    }
    return (0);
}