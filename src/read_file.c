#include "header.h"

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
    return str;
}

