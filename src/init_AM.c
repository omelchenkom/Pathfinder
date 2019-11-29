#include "header.h"

void init_adjacency_matrix(t_App *app) {
    app->AM = malloc(app->SIZE * app->SIZE * sizeof(int));
    for (int i = 0; i < app->SIZE; i++)
        for (int j = 0 ; j < app->SIZE; j++) {
            if (i == j)
                app->AM[i * app->SIZE + j] = 0;
            else
                app->AM[i * app->SIZE + j] = 1000000000;
        }
}

