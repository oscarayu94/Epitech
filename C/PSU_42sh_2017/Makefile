##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## BY 42SH TEAM
##

SRC 	=	main.c				\
		input_handle.c			\
		tree/tree.c			\
		tree/tree_loop.c		\
		tree/initialize_tree.c		\
		tree/instructions_handle.c	\
		2_pointer_array/put_in_array.c	\
		2_pointer_array/memory_handle.c	\
		2_pointer_array/pwd.c		\
		cd_stuff/cd2.c			\
		cd_stuff/cd.c			\
		env_stuff/home_pwd.c		\
		execve_stuff/execve2.c		\
		execve_stuff/execve.c		\
		getpath.c			\
		path_handler.c			\
		linked_list_stuff/linked_space.c\
		my_puts/my_puts2.c		\
		my_puts/str_handle.c		\
		my_puts/my_putstr_sending_fd.c	\
		my_puts/str_cmp.c		\
		options/option.c		\
		redirection/double_left_red.c	\
		redirection/input_red.c		\
		redirection/output_red.c	\
		redirection/pipe.c		\
		set_env/set_env.c		\
		set_env/set_env2.c		\
		history.c			\
		signal/signal.c


OBJ	=	$(SRC:.c=.o)

NAME 	=	42sh

RM	=	rm -rf

all:	$(NAME)


$(NAME):	$(OBJ)
	gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	$(RM) $(NAME)

fclean:	clean
	rm -rf $(OBJ) $(NAME) *~ *#

re:	fclean all
