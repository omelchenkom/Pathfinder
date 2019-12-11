#ifndef HEADER_H
#define HEADER_H

#include "libmx.h"

typedef struct s_APP {
    int SIZE;
    char **city;
    int *AM;
    int *dist_M;
    char **parsed_lines_array;
    char *file_to_str;
    int invalid_line_number;
    char *file_name;
    int k;
} t_App;

 typedef struct {
        int *path;
        int size;
        int max_size;
    } t_stack;

typedef enum Err {
    Invalid_Number_Of_CommandLine,
    File_Doesnt_Exist,
    File_Is_Empty,
    Line1_isnt_valid,
    Line_isnt_Valid,
    Invalid_Number_of_Islands,
    LINE_ERROR_SLASH,
} e_Error;

void print_distance(t_App *app, t_stack *st);

void init_stack(t_stack **st, t_App *app, int i, int j);
void push_in_stack(t_stack *st, int elem);
int pop_from_stack(t_stack *st);
int get_from_stack(t_stack *st);
void restore_path_Helper(t_App *app, t_stack *st);
void restore_allpaths_from_to(t_App *app, int i, int j);
bool is_next(t_App *app, t_stack *st, int next);

int my_atoi(char *s);
bool is_valid_name(char *s);
bool parse_line(char *line, char **arg1, char **arg2, int *arg3);
void init_city(t_App *app);
void push_element_in_city(char *elem, t_App *app);
int index_in_city(char *elem, t_App *app);
void init_adjacency_matrix(t_App *app);
char *read_file(char *argv[], t_App *app);
void parse_rest_of_lines(t_App *app, char **str_parsed);

void mx_printerr(const char *s);
bool mx_isdigit(int c);
bool mx_isalpha(int c);

void initialize(int argc, char *argv[], t_App *app);
void cast_error_message(e_Error err, t_App *app);
void make_allpaths_and_print(t_App *app);
void make_cost_matrix(t_App *app);
void print_path_info(t_App *app, t_stack *st);
void free_all( t_App *app);

#endif

