##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	../src/MapGenerator.cpp	\
		../src/Sfx.cpp			\

OBJ =	$(SRC:.cpp=.o)

NAME =	unit_tests

TEST_NAME = map_exists

all:	$(NAME)

$(NAME):
	@echo "I'm afraid I can't do that, Dave."
	@echo "USAGE: make tests_run"

clean:
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean

	rm -f $(NAME)

re:	fclean all

tests_run:	
	g++ -o unit_tests $(SRC) tests.cpp --coverage -lcriterion -lsfml-audio
	./unit_tests


#endif
