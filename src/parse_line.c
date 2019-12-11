#include "header.h"

bool is_valid_name(char *s);

bool parse_line(char *line, char **arg1, char **arg2, int *arg3) {
    int dash_idx = mx_get_char_index(line, '-');
    int coma_idx = mx_get_char_index(line, ',');
    int len = mx_strlen(line);

    if (dash_idx == -1) return false;
    if (coma_idx == -1) return false;
    if (len == 0) return false;
    if (dash_idx > coma_idx ) return false;

    *arg1 = mx_strndup(line, dash_idx);
    *arg2 = mx_strndup(line + dash_idx + 1, coma_idx - dash_idx - 1);
    char *number = mx_strndup(line + coma_idx + 1, len - coma_idx - 1);

    if (!is_valid_name(*arg1) || !is_valid_name(*arg2))
        return false;

    *arg3 = my_atoi(number);
    if (*arg3 == -1 || *arg3 == 0)
        return false;
    free(number);
    return true;
}

bool is_valid_name(char *s) {
    if (mx_strlen(s) == 0)
        return false;
    for (int i = 0; s[i] != '\0'; i++)
        if(!mx_isalpha(s[i])) return false;
    return true;
}

