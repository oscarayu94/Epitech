##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile rebirth for library
##

#ifndef _MAKE_
#define _MAKE_

SRC = *.c
OBJ = $(SRC: .c=.o)
NAME = librb.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv -i librb.a ../lib

clean:	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

#endif
