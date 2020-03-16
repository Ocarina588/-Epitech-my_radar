/*
** EPITECH PROJECT, 2019
** time
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

tim_t *init_time(void)
{
    tim_t *time = malloc(sizeof(tim_t));
    time->delay = sfClock_create();
    time->fps_clock = sfClock_create();
    time->old_time = sfClock_getElapsedTime(time->delay).microseconds;
    time->fps = 0;
    time->dt = 0;
    return (time);
}

void get_fps(tim_t *time)
{
    if (sfClock_getElapsedTime(time->fps_clock).microseconds >= 1000000 / 8) {
        time->fps = 1 / time->dt;
        sfClock_restart(time->fps_clock);
    }
}

void manage_time(window_t *window)
{
    tim_t *time = window->time;
    long int old_time = time->old_time;
    time->old_time = sfClock_getElapsedTime(time->delay).microseconds;
    time->dt = (time->old_time - old_time) / 1000000.0F;
    get_fps(time);
}