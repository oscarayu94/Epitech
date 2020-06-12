##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	nm.c
		obj

SRC1 =	nm.c

SRC2 = objudmp.c

OBJ =	$(SRC:.c=.o)

NAME =	all

NAME2 = my_nm

NAME3 = my_objdump

all:	$(NAME)

$(NAME):
	gcc -o  $(NAME) $(SRC)

nm:
	gcc -o $(NAME1) $(SRC1)

objdump:
	gcc -o $(NAME2) $(SRC2)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

tests_run:	
	gcc -o unit_tests $(SRC) tests/test_project.c --coverage -lcriterion
	./unit_tests

#endif
