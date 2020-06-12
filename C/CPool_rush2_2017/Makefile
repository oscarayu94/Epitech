##
## EPITECH PROJECT, 2017
## MAKEFILE
## File description:
## 
##
SRC	=	rush2.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	*.c -I ./include/ -L ./lib/my -lmy

NAME	=	rush2

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re:	fclean all

