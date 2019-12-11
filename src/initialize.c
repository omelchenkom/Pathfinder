#include "header.h"

void init_city(t_App *app);
int index_in_city(char *elem, t_App *app);
void initialize(int argc, char *argv[], t_App *app) {

    app->city = NULL;
    app->AM = NULL;
    app->dist_M = NULL;
    app->parsed_lines_array = NULL;
    app->file_to_str = NULL;

    if (argc != 2) {
        cast_error_message(Invalid_Number_Of_CommandLine, app);
    }
    char *str = read_file(argv, app);

    app->parsed_lines_array = mx_strsplit(str, '\n');
    char **str_parsed = app->parsed_lines_array;
    app->SIZE = my_atoi(str_parsed[0]);

    if (app->SIZE  == 0 && str_parsed[1] == NULL)
        exit(0);

    if (app->SIZE  == 0 && str_parsed[1])
        cast_error_message(Invalid_Number_of_Islands, app);

    if (app->SIZE == -1)
        cast_error_message(Line1_isnt_valid, app);
    parse_rest_of_lines(app, str_parsed);
    if (app->city[app->SIZE - 1] == NULL) {
        cast_error_message(Invalid_Number_of_Islands,app);
    }
}
void init_city(t_App *app) {
    app->city = malloc(app->SIZE * sizeof (char *) + 1);
    if (app->city == NULL) {
        exit(1);
    }
    for (int i = 0; i < app->SIZE + 1; i++) {
        app->city[i] = NULL;
    }
}
int index_in_city(char *elem, t_App *app) {
    for (int i = 0; i < app->SIZE; i++)
        if ( mx_strcmp(app->city[i], elem) == 0)
            return i;
    return -1;
}

