#include "header.h"

void push_element_in_city(char *elem, t_App *app) {
    char **city = app->city;
    //go through city to find elem
    int i;
    for (i = 0; i < app->SIZE; i++) {
        if (city[i] == NULL)
            break;
        if (mx_strcmp(city[i], elem) == 0)
            return;
    }
    //add elem to city
    if (i < app->SIZE)
        city[i] = mx_strdup(elem);
    else { //  if too many elem
        cast_error_message(Invalid_Number_of_Islands, app);
    }
}

