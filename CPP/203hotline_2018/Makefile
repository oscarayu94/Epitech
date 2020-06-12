##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	main.cpp

OBJ =	$(SRC:.c=.o)

NAME =	203hotline

all:	$(NAME)

$(NAME):
	g++ -Wall -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
