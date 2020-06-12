##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	sort_array_2.c	\
	my_strcmp.c	\
	my_swamp.c	\
	act_print_tab.c	\

OBJ =	$(SRC:.c=.o)

NAME =	Sortie

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
