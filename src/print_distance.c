#include "header.h"

void print_distance(t_App *app, t_stack *st) {
    mx_printstr("Distance: ");
    int total_dist = 0;
    for(int i = st->size - 1; i >= 2; i--) {
        int dist = app->AM[st->path[i] * app->SIZE + st->path[i + 1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" + ");
    }
    if (total_dist != 0) {
        int dist = app->AM[st->path[2] * app->SIZE + st->path[1]];
        total_dist += dist;
        mx_printint(dist);
        mx_printstr(" = ");
    }
    else
       total_dist = app->AM[st->path[2] * app->SIZE + st->path[1]];
    mx_printint(total_dist);
    mx_printstr("\n");
}

