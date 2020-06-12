##
## EPITECH PROJECT, 2020
## Makefiel
## File description:
## Makefile
##

SRC	=	src/Box.cpp \
		src/PapaXmasConveyorBelt.cpp \
		src/LittlePony.cpp \
		src/Toy.cpp \
		src/GiftPaper.cpp \
		src/PapaXmasTable.cpp \
		src/Object.cpp \
		src/Wrap.cpp \
		src/Teddy.cpp \
		main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	santa

all:	$(NAME)

$(NAME):	$(OBJ)
	@cd tests; make; cd ..;
	@g++ -o $(NAME) $(OBJ)

clean:
	@cd tests; make clean; cd ..;
	@rm -f *.o

fclean:	clean
	@cd tests; make fclean; cd ..;
	@rm -f $(NAME)
	@rm -f UnitTests

re:	fclean all
	@cd tests; make clean; cd ..;
	@rm -f *.o

unit_tests:
	cd tests ;make
