/*
** EPITECH PROJECT, 2019
** main
** File description:
** sdf
*/

#include "my.h"
#include "radar.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int tireh(void)
{
    my_putstr("L:   activer/desactiver le contour des avions et radars\n");
    my_putstr("S:   activer/desactiver les sprites des avions et radars\n");
    my_putstr("Q:   activer/desactiver l'affichage de la quad tree\n");
    my_putstr("ESC: activer/desactiver la mise en pause\n");
    my_putstr("I:   activer/desactiver l'affichage des informations\n");
    my_putstr("Le script gere les nombres a vergules\n");
    return (1);
}

int is_goal(plane_t plane)
{
    float a = plane.coord.x;
    float b = plane.goal.x;
    float c = plane.coord.y;
    float d = plane.goal.y;
    float e = b - a;
    float f = d - c;

    if (
        !((e > 0 && plane.vx > 0) || (e < 0 && plane.vx < 0))
        &&
        !((f > 0 && plane.vy > 0) || (f < 0 && plane.vy < 0))
        )
            return (1);
    return (0);
}

int main(int ac, char **av)
{
    elements_t *elements = NULL;
    window_t *window = init_window();
    qt_t *quad_tree;
    ui_t *ui = init_ui();
    if (ac == 2 && !my_strcmp("-h", av[1]) && tireh())
        return (0);
    if ((ac != 2 && error_argument()) ||
        (!(elements = init_elements(av[1])) && error_script()))
        return (84);
    while (sfRenderWindow_isOpen(window->render)) {
        quad_tree = new_quad_tree(new_rec(0, 0, 1920, 1080));
        insert_manager(elements, quad_tree);
        wheel_manager(elements, window);
        my_radar_mangement(elements, window, quad_tree, ui);
        destroy(elements, quad_tree);
        free_quad_tree(quad_tree);
        manage_time(window);
    }
    free_manager(elements, window);
    return (0);
}