/*
** EPITECH PROJECT, 2018
** pwd
** File description:
** BY 42sh team
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

void	geta_pwd_loop(list_t *b)
{
	char	cwd[1024];

	if (getcwd(cwd, 1024) != NULL) {
		my_putstr_with_fd(cwd, b->fd);
		my_putchar_with_fd('\n', b->fd);
	}
	else {
		b->truee = 0;
		my_putstr_error("pwd: not working comand");
	}
}

void	geta_pwd(list_t *b, space_t *a)
{
	if ((my_strcmp(a->name , "pwd")) == 1) {
		b->number = 0;
		if (arguments_after(a) != 0) {
			b->truee = 0;
			my_putstr_error("pwd: ignoring ");
			my_putstr_error("non-option arguments\n");
		}
		geta_pwd_loop(b);
	}
}
