//
// Created by Oleg on 2019-10-24.
//
#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    if (list == NULL) return;

    t_list *new_n = mx_create_node(data);
    if (new_n == NULL) return;

    new_n->next = *list;
    *list = new_n;
}

