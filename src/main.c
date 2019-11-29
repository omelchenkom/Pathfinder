#include "libmx.h"
#include "header.h" 

int main(int argc, char *argv[]) {
    t_App *app = malloc(sizeof(t_App));

    initialize(argc, argv, app);
    make_allpaths_and_print(app);
    free_all(app);
    return 0;
}

