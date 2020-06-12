##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	main.c	\
	count_letters.c	\
	count_spaces.c	\
	helping_functions.c	\
	two_letters.c	\
	several_letters.c	\
	no_middle_letter.c	\
	middle_letter.c	\

OBJ =	$(SRC:.c=.o)

NAME =	USNameFormatter

all:	$(NAME)

$(NAME):
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
