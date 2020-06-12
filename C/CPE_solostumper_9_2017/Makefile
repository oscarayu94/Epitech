##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	main.c		\
	my_putchar.c	\
	my_putstr.c	\
	my_strlen.c	\

OBJ =	$(SRC:.c=.o)

NAME =	palindrome

all:	$(NAME)

$(NAME):
	gcc -Wall -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
