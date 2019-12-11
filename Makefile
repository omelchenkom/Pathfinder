NAME = pathfinder
INC = ./inc/header.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./header.h ./libmx.h

SRC = ./main.c ./mx_isalpha.c ./mx_isdigit.c ./mx_printerr.c \
	./free_all.c ./initialize.c ./restore_all_paths.c ./print.c \
	./print_err.c ./make_DM.c ./print_distance.c ./path.c ./atoi.c \
	./parse_line.c ./init_AM.c ./read_file.c ./push_city.c ./parse_rest.c \

SRCS = ./src/main.c ./src/mx_isalpha.c ./src/mx_isdigit.c \
	./src/mx_printerr.c ./src/free_all.c ./src/initialize.c \
	./src/restore_all_paths.c ./src/print.c ./src/print_err.c \
	./src/make_DM.c ./src/print_distance.c ./src/path.c ./src/atoi.c \
	./src/parse_line.c ./src/init_AM.c ./src/read_file.c ./src/push_city.c \
	./src/parse_rest.c \

OBJ = ./main.o ./mx_isalpha.o ./mx_isdigit.o ./mx_printerr.o ./free_all.o \
    ./initialize.o ./restore_all_paths.o ./print.o ./print_err.o ./make_DM.o \
	./print_distance.o ./path.o ./atoi.o ./parse_line.o ./init_AM.o \
	./read_file.o ./push_city.o ./parse_rest.o \

OBJO = ./obj/main.o ./obj/mx_isalpha.o ./obj/mx_isdigit.o \
	./obj/mx_printerr.o ./obj/free_all.o ./obj/initialize.o \
	./obj/restore_all_paths.o ./obj/print.o ./obj/print_err.o \
	./obj/make_DM.o ./obj/print_distance.o ./obj/path.o ./obj/atoi.o \
	./obj/parse_line.o ./obj/init_AM.o ./obj/read_file.o ./obj/push_city.o \
	./obj/parse_rest.o \

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall
install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@cp $(INCLIB) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/obj
clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)
reinstall: clean all

