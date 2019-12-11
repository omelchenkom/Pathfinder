#include "header.h"

void parse_rest_of_lines(t_App *app, char **str_parsed) {
    init_city(app);
    init_adjacency_matrix(app);

    for (int i = 1; str_parsed[i] != NULL; i++) {
        char *arg1 = NULL;
        char *arg2 = NULL;
        int arg3 = -1;
        if(app->k != 0 && app->k <= i)
            cast_error_message(LINE_ERROR_SLASH, app);
        if (parse_line(str_parsed[i], &arg1, &arg2, &arg3)) {
            push_element_in_city(arg1, app);
            push_element_in_city(arg2, app);
            int i = index_in_city(arg1, app);
            int j = index_in_city(arg2, app);
            app->AM[i * app->SIZE + j] = arg3;
            app->AM[j * app->SIZE + i] = arg3;
        }
        else {
            free(arg1);
            free(arg2);
            app->invalid_line_number = i + 1;
            cast_error_message(Line_isnt_Valid, app);
        }
        free(arg1);
        free(arg2);
    }
    if(app->k != 0)
        cast_error_message(LINE_ERROR_SLASH, app);
}

