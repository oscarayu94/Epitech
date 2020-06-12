
##
## EPITECH PROJECT, 2017
## 
## File description:
## 
##

#ifndef MAKE
#define MAKE
SRC 	=	main.c			\
		my_puts.c		\
		my_puts2.c		\
		getpath.c		\
		put_in_array.c		\
		yolotron_vm.c		\
		put_comands.c		\
		my_getnbr.c		\
		live.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	corewar

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)	
	gcc -g -Wall -Werror -o $(NAME) $(SRC) 
clean:
	$(RM) $(NAME)

fclean: clean
	rm -f $(OBJ) $(NAME) *~ *#

re:	fclean all
