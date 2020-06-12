##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

#ifndef _MAKE_
#define _MAKE_

SRC= 		get_nbr.c	\
		StrHandle.c	\
		number_handle.c	\
		main.c		\
		Geometry.c

OBJ= 		$(SRC:.c=.o)

NAME=		104intersection

$(NAME):	$(OBJ)
		gcc -g -Wall -Werror -o $(NAME) $(SRC) -lm

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

#endif
