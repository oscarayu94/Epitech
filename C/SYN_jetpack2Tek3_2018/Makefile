##
## EPITECH PROJECT, 2019
## SYN_Jetpack
## File description:
## Makefile
##

CLIENT_PATH = client/src/

SERVER_PATH = server/src/

COMMANDS = player/

FIFO = fifos/utils/

SRC =	$(CLIENT_PATH)main.c  						\
		$(CLIENT_PATH)graphical_interface.c  						\

SERVSRC	=	$(SERVER_PATH)main.c					\

OBJ	=	$(SRC:.cpp=.o)

SERVOBJ	=	$(SERVSRC:.c=.o)

NAME	=	clientJ2T3

SERVNAME =	serverJ2T3

client: $(NAME)

server: $(SERVNAME)

all	:	$(NAME) $(SERVNAME)

rmfifo: 
	rm -rf client/src/fifos/read/myfifo

$(NAME)	:	rmfifo $(OBJ)
	# gcc -g -Wall -Wextra -o $(NAME) $(SRC) -lpthread -lsfml-window -lsfml-graphics -lsfml-system
	  gcc -g -Wall -Wextra -o $(NAME) $(SRC) -lpthread -l c_graph_prog

$(SERVNAME)	:	$(SERVOBJ)
	gcc -g -Wall -Wextra  -o $(SERVNAME) $(SERVSRC)

clean:
	rm -rf $(OBJ)
	rm -rf $(SERVOBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(SERVNAME)
	rm -rf *~ *# *.o

