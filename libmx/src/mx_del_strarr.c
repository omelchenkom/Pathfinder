#include "libmx.h"

void mx_strdel(char **str);

void mx_del_strarr(char ***arr) {
    if (arr == NULL || *arr == NULL) return;
    char ***p = arr;
    char **pp = *arr;
    while (**p != NULL) {
        mx_strdel(*p);
        (*p)++;
    }
    
    free(pp);
    *arr = NULL;
}

