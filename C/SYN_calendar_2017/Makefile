##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

SRC =	tools.c		\
	check_file.c	\
	parser.c	\
	main.c		\

OBJ =	$(SRC:.c=.o)

NAME =	calendar

all:	$(NAME)

$(NAME):
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
