##
## EPITECH PROJECT, 2019
## CNA_groundhog_2019
## File description:
## Makefile
##

SRC	=	src/main.cpp	\
		src/groundhog.cpp

CFLAGS	=	-g3

NAME	=	groundhog

OBJ =	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all