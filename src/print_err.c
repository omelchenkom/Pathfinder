#include "header.h"
static void file_doesnt_exist(t_App *app);
static void file_is_empty(t_App *app);
static void line_isnt_valid(t_App *app);
static void line_error_slash(t_App *app);
void cast_error_message(e_Error err, t_App *app) {
    if (err == Invalid_Number_Of_CommandLine)
        mx_printerr("usage: ./pathfinder [filename]");
    else if (err == File_Doesnt_Exist)
        file_doesnt_exist(app);
    else if (err == File_Is_Empty)
        file_is_empty(app);
    else if (err == Line1_isnt_valid)
        mx_printerr("error: line 1 is not valid");
    else if (err == Line_isnt_Valid)
        line_isnt_valid(app);
    else if (err == Invalid_Number_of_Islands)
        mx_printerr("error: invalid number of islands");
    else if (err == LINE_ERROR_SLASH)
        line_error_slash(app);
    mx_printerr("\n");
    free_all(app);
    exit(1);
}
static void file_doesnt_exist(t_App *app) {
    mx_printerr("error: file ");
    mx_printerr(app->file_name);
    mx_printerr(" does not exist");
}
static void file_is_empty(t_App *app) {
    mx_printerr("error: file ");
    mx_printerr(app->file_name);
    mx_printerr(" is empty");
}
static void line_isnt_valid(t_App *app) {
    mx_printerr("error: line ");
    char *snum = mx_itoa(app->invalid_line_number);
    mx_printerr(snum);
    free(snum);
    snum = NULL;
    mx_printerr(" is not valid");
}
static void line_error_slash(t_App *app) {
    mx_printerr("error: line ");
    char *number_line = mx_itoa(app->k);
    mx_printerr(number_line);
    free(number_line);
    number_line = NULL;
    mx_printerr(" is not valid ");
}

