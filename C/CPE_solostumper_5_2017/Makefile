##
## EPITECH PROJECT, 2017
## Makefile 
## File description:
## Makefile for solostumper 5
##

#ifndef _MAKE_
#define _MAKE_

SRC =	general.c

OBJ =	$(SRC:.c=.o)

NAME =	sort_words

all:	$(NAME)

$(NAME):
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
