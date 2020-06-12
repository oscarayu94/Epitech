#                                                                      
## EPITECH PROJECT, 2017                                                
## Makefile                                                             
## File description:                                                    
## By Oscar                                                             
##                                                                      

#ifndef _MAKE_                                                          
#define _MAKE_                                                          

SRC =   core.c		\
	built_functions.c	\
        my_str_to_word_array.c	\
	my_str_to_wordtab.c	\
	my_print_tab.c	\
        my_strcmp.c		\
	my_putchar.c		\
	my_str_concatenate.c	\
	my_str_concatenate_equal.c	\
	my_strdup.c		\
	my_strlen.c		\
	my_tabcpy.c		\
	my_putstr.c		\

OBJ =   $(SRC:.c=.o)

NAME =  mysh1

all:    $(NAME)
#-Wall -Werror -o $(NAME) $(SRC)
$(NAME):
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean: clean

	rm -f $(NAME)

re:     fclean all

#endif 
