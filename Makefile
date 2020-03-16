##
## EPITECH PROJECT, 2019
## make file window
## File description:
## sdf
##

SRC	=	src/main.c	\
		src/read_script.c	\
		src/read_script_bis.c	\
		src/window_manager.c	\
		src/free.c	\
		src/event_manager.c	\
		src/create_shape.c	\
		src/angle_compute.c	\
		src/quad_tree.c	\
		src/math.c	\
		src/points_management.c	\
		src/list_operation.c	\
		src/quad_tree_bis.c	\
		src/time.c	\
		src/text.c	\
		src/wheel.c	\
		src/sat.c	\
		src/ui.c	\
		src/error.c	\
		src/pause.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_radar

LDFLAGS	=	-Llib -lmy -lm -l csfml-graphics -l csfml-window -l csfml-system

CFLAGS	=	-Iinclude -g

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib/my/
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:     fclean all

