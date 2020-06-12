##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	src/main.cpp \
		src/Adresses.cpp	

OBJ =	$(SRC:.c=.o)

NAME =	autoCompletion

all:	$(NAME)

$(NAME):
	g++ -g -Wall -Wextra -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
