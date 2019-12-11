#include "header.h"

static char *get_name_by_id(int i, t_App *app);
static void print_line(void);
static void print_path(t_App *app, t_stack *st);
static void print_route(t_App *app, t_stack *st);

void print_path_info(t_App *app, t_stack *st) {
    print_line();
    mx_printstr("\n");
    print_path(app, st);
    print_route(app, st);
    print_distance(app, st);
    print_line();
    mx_printstr("\n");
}

static char *get_name_by_id(int i, t_App *app) {
    return app->city[i];
}

static void print_line(void) {
    char s[]= "========================================";
    mx_printstr(s);
}

static void print_path(t_App *app, t_stack *st) {
    mx_printstr("Path: ");
    mx_printstr(get_name_by_id (st->path[0], app));
    mx_printstr(" -> ");
    mx_printstr(get_name_by_id(st->path[1], app));
    mx_printstr("\n");
}

static void print_route(t_App *app, t_stack *st) {
    mx_printstr("Route: ");
    for(int i = st->size; i >= 2; i--) {
        mx_printstr(get_name_by_id(st->path[i], app));
        mx_printstr(" -> ");

    }
    mx_printstr(get_name_by_id(st->path[1], app));
    mx_printstr("\n");
}

