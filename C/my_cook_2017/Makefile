##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Luis Angel Macias de la Cruz
##

SRC	=	cooking.c	\
		my_puts.c	\
		menu.c		\
		event_list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_cook

all	:	$(NAME)	

$(NAME)	:	$(OBJ)
	gcc -g -Werror -Wall -o $(NAME) $(SRC) -l "c_graph_prog"

clean	:
	rm -f $(OBJ)

fclean	:	 clean
	rm -f $(NAME)

re	:	fclean all
