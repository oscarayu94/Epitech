##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =   main_rebuild.c \
	my_putchar.c \
	my_putstr.c \
	my_getnbr.c \

OBJ =	$(SRC:.c=.o)

NAME =  matchstick

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
