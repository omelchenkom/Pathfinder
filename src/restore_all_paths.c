#include "header.h"

bool is_next(t_App *app, t_stack *st, int next) {
    int k = get_from_stack(st);
    int i = st->path[0];
    int *AM = app->AM;
    int *DM = app->dist_M;
    int size = app->SIZE;

    if (k != next) {
        if (DM[i * size + k] - AM[k * size + next] == DM[i * size + next]) {
            return true;
        }
    }
    return false;
}

void restore_path_Helper(t_App *app, t_stack *st) {
    // base case
    if (get_from_stack(st) == st->path[0]) {
        print_path_info(app, st);
        return;
    }
    else { // recursive case
        // for all adjecency virtecies to j
        for (int next = 0; next < app->SIZE; next++) {
            if (is_next(app, st, next)) {
                // choose
                push_in_stack(st, next);
                // explore
                restore_path_Helper(app, st);
                // un-choose
                pop_from_stack(st);
            }
        }
    }
}

void restore_allpaths_from_to(t_App *app, int i, int j) {
    t_stack *st = NULL;
    init_stack(&st, app, i, j);

    restore_path_Helper(app, st);

    free(st->path);
    free(st);
}

