##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	src/main.cpp		\
		src/IO.cpp			\
		src/BigDecimal.cpp	\
		src/Chipset.cpp		\
		src/CPU.cpp			\
		src/Double.cpp		\
		src/Factory.cpp		\
		src/Float.cpp		\
		src/Int8.cpp		\
		src/Int16.cpp		\
		src/Int32.cpp		\
		src/IOperand.cpp	\
		src/Memory.cpp		\

OBJ =	$(SRC:.c=.o)

NAME =	abstractVM

all:	$(NAME)

$(NAME):
	g++ -Wall -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
