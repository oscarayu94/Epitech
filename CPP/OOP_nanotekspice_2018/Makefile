##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	nano.cpp	\
		Errors.cpp	\
		Components/LogicDoors.cpp	\
		Components/Component.cpp

NAME	=	nanotekspice

all	:
	g++ -o $(NAME) $(SRC) -g -Wall -Wextra -Werror 

re	:	fclean all

fclean	:
	rm -rf $(NAME) *.o *~ *.gcda *.gcno *# 