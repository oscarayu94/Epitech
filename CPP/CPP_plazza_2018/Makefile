##
## EPITECH PROJECT, 2019
## CCP_plazza_2018
## File description:
## Makefile
##

SRC	=	main.cpp	\
		reception/parse_input/Parse_input.cpp	\
		reception/Reception.cpp	\
		pizza/APizza.cpp	\
		pizza/types/Regina.cpp	\
		pizza/types/Margarita.cpp	\
		pizza/types/Americana.cpp	\
		pizza/types/Fantasia.cpp	\
		utils/Utils.cpp	\
		kitchen/Kitchen.cpp	\
		cook/Cook.cpp	\
		ingredients/Ingredient.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	plazza

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	g++ -g -Wall -Wextra -o $(NAME) $(SRC) -lpthread
	rm -rf fifos/read/myfifo* fifos/write/myfifo*

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

f	:
	rm -rf fifos/read/myfifo* fifos/write/myfifo*