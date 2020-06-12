SRC_DIR=	.

# Must list all project files without the main() function
# Criterion uses its own main() ;
# having a main() in any .c file will have the build fail

SRC=		$(SRC_DIR)/my_putchar.c


SRC_UT_DIR=	.

# Must list all files containing unit tests

SRC_UT=		$(SRC_UT_DIR)/test.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=		-Wall -Wextra --coverage

LDFLAGS=	-lcriterion -lgcov

NAME=		units

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:		
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
