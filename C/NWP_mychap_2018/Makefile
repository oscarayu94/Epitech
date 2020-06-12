##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	main.c	\
		my_boots.c

OBJ =	$(SRC:.c=.o)

NAME =	client

all:	$(NAME)

$(NAME):
	gcc -Wall -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
