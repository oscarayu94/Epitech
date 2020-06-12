##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	basis.c

OBJ =	$(SRC:.c=.o)

NAME =	basis

LIBNAME = libmy_malloc.so

all:	$(NAME)

$(NAME):
	gcc -c -fpic $(SRC)
	gcc -shared -o $(LIBNAME) *.o

test./:
	gcc -o test test.c

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
