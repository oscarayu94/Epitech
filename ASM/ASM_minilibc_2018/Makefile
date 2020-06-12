##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	strlen.asm

LIB_NAME =	libasm.so

NAME = 		test

all:	$(NAME)

nasm:
	nasm -f elf64 $(SRC) 

$(NAME): nasm
	gcc -shared *.o -o $(LIB_NAME)
	gcc -g -o  $(NAME) main_test.c -L. -lasm -fno-builtin 

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME) *.so *~ *#

re:	fclean all

#endif
