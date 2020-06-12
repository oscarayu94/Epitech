##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	main.c	\
	my_putchar.c	\
	my_putstr.c	\
	my_strcmp.c	\
	my_print_tab.c	\
	direction.c

OBJ =	$(SRC:.c=.o)

NAME =	generator

all:	$(NAME)

$(NAME):
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
