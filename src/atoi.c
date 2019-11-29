#include "header.h"

int my_atoi(char *s) {
    int res = 0;
    while (*s != '\0') {
        if (!mx_isdigit(*s)) return -1;
        res = 10 * res + (*s) - '0';
        s++;
    }
    if (res == 0) res = -1;
    return res;
}

