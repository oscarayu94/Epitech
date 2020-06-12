
#ifndef _MAKE_
#define _MAKE_

SRC =	core.c	\


OBJ =	$(SRC:.c=.o)

NAME =	geekNameFormatter

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
