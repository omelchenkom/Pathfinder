#include "header.h"

void restore_all_paths(t_App *app) {
    for (int i = 0; i < app->SIZE; i++) {
        for (int j = i + 1; j < app->SIZE; j++)
            restore_allpaths_from_to(app, i, j);
    }
}

void make_allpaths_and_print(t_App *app) {
    make_cost_matrix(app);
    restore_all_paths(app);
}

void init_stack(t_stack **st, t_App *app, int i, int j) {
    *st = malloc(sizeof(t_stack)); 
    if ((*st) == NULL) exit(1);

    (*st)->max_size = app->SIZE;
    (*st)->path = malloc((*st)->max_size * sizeof(int) + 1);
    (*st)->path[0] = i;
    (*st)->path[1] = j;
    (*st)->size = 1;
}

void push_in_stack(t_stack *st, int elem) {
    if (st->size < st->max_size) {
        st->size++;
        st->path[st->size] = elem;
    }
}

int pop_from_stack(t_stack *st) {
    if (st->size > 1) {
        st->size--;
        return st->path[st->size + 1];
    }
    return st->path[1]; // всегда первый элемент не можно убрать.
}

int get_from_stack(t_stack *st) {
    return st->path[st->size];
}

