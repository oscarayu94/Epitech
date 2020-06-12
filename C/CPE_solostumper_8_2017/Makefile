##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

SRC =	main.c \
	my_print_tab.c	\
	my_putstr.c	\
	my_putchar.c	

OBJ =	$(SRC:.c=.o)

NAME =	frenchNameFormatter

all:	$(NAME)

$(NAME):
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all
