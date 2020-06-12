##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	my_hunter.c	\
	error.c		\
	core.c		\
	tools.c		\
	clean_hunter.c	\

NAME =	my_hunter

all:	$(NAME)

$(NAME):
	gcc -g -Wall -Werror -o $(NAME) $(SRC) -l "c_graph_prog"

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
