##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## rush 3
##

SRC	=	main.cpp	\
		init.cpp	\
		Sfml/SfmlMode.cpp	\
		Ncurses/NcursesMode.cpp	\
		Datas/Cpu.cpp	\
		Datas/DateTime.cpp	\
		Datas/HostUserName.cpp	\
		Datas/KernelSystem.cpp	\
		Datas/MonitorCore.cpp	\
		Datas/Network.cpp	\
		Datas/Ram.cpp

NAME	=	MyGKrellm

OBJ	=	$(SRC:.cpp=.o)

FLAGS =	-Wall -Wextra

LIB = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lncurses

HEAD	=	-I.

all:	$(NAME)

$(NAME):	$(OBJS)
	@g++ -o $(NAME) $(SRC) $(LIB) $(FLAGS) $(HEAD)

clean:
	@rm -rf $(OBJ)
fclean:		clean
	@rm -rf $(NAME)

re:	fclean all
