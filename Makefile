##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

CFLAGS = -W -Werror -Wextra -Wall

SRC		=	sources/

SRC_C	=	main.c				\
			main_aux_funcs.c	\
			function_attack.c 	\
			function_matrix.c   \
			function_signals.c 	\
			function_signals2.c \
			function_prints.c   \
			check_functions.c 	\
            basic_functions/my_putchar.c	    \
            basic_functions/my_put_nbr.c	    \
			basic_functions/my_putstr.c 		\
			basic_functions/my_strlen.c			\
			basic_functions/my_getnbr.c			\
			basic_functions/my_strdup.c			\
			basic_functions/my_strcmp.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./include

NAME = 		navy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o  $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean