#include "header.h"

static void check_line_n(char *str, t_App *app);

char *read_file(char *argv[], t_App *app) {
    app->file_name = argv[1];
    // Check if file exists
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        close(fd);
        cast_error_message(File_Doesnt_Exist, app);
    }
    close(fd);

    //read file and validate if file empty
    app->file_to_str = mx_file_to_str(argv[1]);
    char *str = app->file_to_str;
    if (mx_strlen(str) == 0) {
        cast_error_message(File_Is_Empty, app);
    }

    check_line_n(str, app);
    return str;
}

static void check_line_n(char *str, t_App *app) {

    if (str[0] == '\n')
        cast_error_message(Line1_isnt_valid, app);

    int j  = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
            j++;
        if (str[i] == '\n' && str[i + 1] == '\n')
        {
            app->k  = j + 1;
            break;
        }
    }
}

