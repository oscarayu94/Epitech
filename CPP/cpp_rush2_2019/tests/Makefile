##
## EPITECH PROJECT, 2020
## cpp_rush2_2019
## File description:
## Makefile
##


SRC =		myUnitTests.cpp \
		../src/Toy.cpp \
		../src/Object.cpp \
		../src/Wrap.cpp \
		../src/Teddy.cpp \
		../src/PapaXmasTable.cpp \
		../src/GiftPaper.cpp \
		../src/Box.cpp \
		../src/LittlePony.cpp \
		../src/PapaXmasConveyorBelt.cpp 

OBJ	=	$(SRC:.cpp=.o)

NAME	=	UnitTests

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(SRC)
	mv $(NAME) ..

re:	fclean all

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME) *.o *~ *.gcda *.gcno *# 
