##
## EPITECH PROJECT, 2019
## PSU_ftrace_2018
## File description:
## Makefile
##

SRC	=	main.c	\
		fork.c	\
		print.c	\
		functions.c	\
		get_path/get_path.c	\
		elf/elf.c	\
		sigint_catch/signals.c

NAME	=	ftrace

OBJ	=	$(SRC:.c=.o)

all	:	ftrace

NAME	:	$(NAME)

$(NAME)	:	$(OBJ)
	#nasm -f elf64 -o test.o test.asm ;ld -s -o hello test.o
	gcc -g -Wall  -Wextra -o $(NAME) $(OBJ)

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME) $(OBJ) *~  *# *.o

re	:	fclean all

