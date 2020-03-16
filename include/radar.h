/*
** EPITECH PROJECT, 2019
** radar
** File description:
** sdf
*/

#ifndef RADAR_H
#define RADAR_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Keyboard.h>

typedef struct tim_t
{
    sfClock *delay;
    sfClock *fps_clock;
    long int old_time;
    float dt;
    int fps;
} tim_t;

typedef struct text_t
{
    sfText *text;
    sfFont *font;
} text_t;

typedef struct info_t
{
    int x;
    int y;
    int w;
    int h;
} info_t;

typedef struct points_t
{
    sfVector2f ne;
    sfVector2f nw;
    sfVector2f se;
    sfVector2f sw;
} points_t;

typedef struct qt_t
{
    struct plane_t *plane_head;
    sfRectangleShape *boundary;
    struct info_t inf;
    int capacity;
    int is_divided;
    struct qt_t *ne;
    struct qt_t *nw;
    struct qt_t *se;
    struct qt_t *sw;
} qt_t;

typedef struct window_t
{
    sfRenderWindow *render;
    sfSprite *background;
    sfTexture *t_backround;
    sfVideoMode mode;
    tim_t *time;
    int info;
    int draw_quad_tree;
    int pause;
    long double micro;
    sfEvent event;
} window_t;

typedef struct plane_t
{
    sfRectangleShape *hitbox;
    sfVector2f goal;
    sfVector2f coord;
    sfVector2f decal;
    struct points_t points;
    float angle;
    float size;
    float vx;
    float vy;
    float speed;
    float delay;
    struct plane_t *next;
    struct plane_t *wheel;
    struct plane_t *list;
    int destroyed;

} plane_t;

typedef struct radar_t
{
    sfSprite *eye;
    sfCircleShape *zone;
    sfVector2f coord;
    float radius;
}radar_t;

typedef struct elements_t
{
    sfTexture *t_plane;
    sfTexture *t_radar;
    plane_t *wheel;
    plane_t *plane;
    plane_t *list;
    int nb_plane;
    radar_t *radar;
    int nb_radar;
    int draw_eye;
    int draw_zone;
} elements_t;


typedef struct ui_t
{
    text_t *fps;
    text_t *timer;
    text_t *on;
    text_t *off;
    text_t *shape;
    text_t *sprites;
    text_t *quad_tree;
    sfSprite *background_pause;
    sfTexture *t_background_pause;
    sfSprite *pause;
    sfTexture *t_pause;
} ui_t;

void draw_text(sfText *text, window_t *window, sfVector2f vect);
text_t *new_text(char *font, float x, float y, sfColor color);
void draw_pause(ui_t *ui, window_t *window);
void init_background_pause(ui_t *ui);
void init_pause(ui_t *ui);
int error_script(void);
int error_argument(void);
int colide_radar(plane_t *a, plane_t *b, elements_t *elements);
void draw_ui(ui_t *ui, window_t *window, elements_t *elements);
float msin(float angle);
float mcos(float angle);
void find_colide(plane_t *plane, qt_t *quad_tree, elements_t *elements);
void destroy(elements_t *elements, qt_t *quad_tree);
int colide_plane(plane_t *a, plane_t *b);
void pop_wheel(plane_t **head, plane_t *plane);
void wheel_manager(elements_t *elements, window_t *window);
void init_list(elements_t *elements);
ui_t *init_ui(void);
void text_manager(window_t *window, ui_t *ui, elements_t *elements);
text_t *init_text(char *font);
void manage_time(window_t *window);
tim_t *init_time(void);
void get_fps(tim_t *time);
void insert_manager(elements_t *elements, qt_t *quad_tree);
sfVector2f get_colid_point_circle(plane_t *plane, qt_t *quad_tree);
int insert(plane_t *plane, qt_t *quad_tree);
int colide_quad_tree(plane_t *plane, qt_t *quad_tree);
int len_list(plane_t *head);
void push(qt_t *quad_tree, plane_t *plane);
sfVector2f move_points(plane_t *plane, window_t *window);
void set_points(plane_t *plane);
sfVector2f vector_decal(plane_t *plane);
sfVector2f rotate_point(sfVector2f a, sfVector2f b, float angle);
int is_goal(plane_t plane);
void draw_manager(window_t *window, elements_t *elements,
    qt_t *quad_tree, ui_t *ui);
void draw_quad_tree(qt_t *quad_tree, window_t *window);
qt_t *new_quad_tree(sfRectangleShape *boundary);
sfRectangleShape *new_rec(float x, float y, float w, float h);
info_t get_info(sfRectangleShape *rec);
void subdivide(qt_t *quad_tree);
void draw_radar(window_t *window, elements_t *elements);
void create_zone(elements_t *elements);
void stick_texture(elements_t *elements);
void stick_hitbox(elements_t *elements);
void draw_plane(window_t *window, elements_t *elements);
float compute_angle(plane_t *plane);
float vector_norm(sfVector2f u);
float scalar_product(sfVector2f u, sfVector2f v);
sfVector2f get_direction_vector(plane_t *plane);
void set_vspeed(plane_t *plane);
void create_texture_plane(elements_t *elements);
void create_shape(elements_t *elements);
void event_manager(elements_t *elements_t, window_t *window);
void free_manager(elements_t *elements, window_t *window);
void free_quad_tree(qt_t *quad_tree);
void my_radar_mangement(elements_t *elements,
    window_t *window, qt_t *qt, ui_t *ui);
window_t *init_window(void);
int check_bad_char(char c);
int check_con(char c, int rep_num, int rep_sign, int point);
int fill_element(char *str, float **tab);
int fill_elements(char *str, elements_t *elements);
elements_t *init_elements(char *str);
int count_elements(char **tab, elements_t *elements);
int count_lines(char *str);
char **read_script(char *str);

#endif