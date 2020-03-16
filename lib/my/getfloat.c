/*
** EPITECH PROJECT, 2019
** getfloat
** File description:
** sdf
*/

#include "my.h"

int nb_len(int nb)
{
    int tmp = nb;
    int len = 0;

    while (tmp) {
        tmp /= 10;
        len++;
    }
    return (nb ? len : 1);
}

int len_to_divid(char *str)
{
    int len = 0;
    for (int i = 0; str && str[i] && (str[i] >= '0' && str[i] <= '9'); i++)
        len++;
    return (len);
}

double getdouble(char *str)
{
    int first = my_getnbr(str);
    int second = 0;
    int rep_sign = 1;
    int i = 0;
    for (i = 0; str[i] ; i++) {
        if ((str[i] == '-' || str[i] == '+') && !rep_sign)
            break;
        if (str[i] >= '0' && str[i] <= '9')
            rep_sign = 0;
        if (str[i] == ' ')
            break;
        if (str[i] == '.' && (str[i + 1] <= '9' && str[i + 1] >= '0')) {
            second = my_getnbr(str + i + 1);
            break;
        }
    }
    if (first < 0)
        second *= -1;
    return (first + (double)second / my_compute_power_rec(10,
        len_to_divid(str[i] ? str + i + 1 : str + i)));
}

float getfloat(char *str)
{
    int first = my_getnbr(str);
    int second = 0;
    int rep_sign = 1;
    int i = 0;
    for (i = 0; str[i] ; i++) {
        if ((str[i] == '-' || str[i] == '+') && !rep_sign)
            break;
        if (str[i] >= '0' && str[i] <= '9')
            rep_sign = 0;
        if (str[i] == ' ')
            break;
        if (str[i] == '.' && (str[i + 1] <= '9' && str[i + 1] >= '0')) {
            second = my_getnbr(str + i + 1);
            break;
        }
    }
    if (first < 0)
        second *= -1;
    return (first + (float)second / my_compute_power_rec(10,
        len_to_divid(str[i] ? str + i + 1 : str + i)));
}