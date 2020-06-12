
/*
** EPITECH PROJECT, 2018
** dele
** File description:
** denode
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

int	arguments_after(space_t *a)
{
	int	i;

	for (i = 0; a != NULL; i++, a = a->next);
	return (i - 1);
}

void	exiting(list_t *b, space_t *a)
{
	if ((my_strcmp(a->name, "exit")) == 1) {
		b->number = 0;
		if (arguments_after(a) != 0) {
			b->truee = -1;
			my_putstr_error("exit: Expression Syntax\n");
		}
		else
			exit(0);
	}
}

char	**comands_options(char **env, char **pwd, list_t *a, char *real_pwd)
{
	char	**car = characters();
	int	g = 0;

	for (int i = 0; car[i] != NULL; i++)
		if (my_strcmp(car[i], a->name) == 1)
			g = 1;
	if (g == 0) {
		exiting(a, a->separ);
		env = set_env(a, a->separ, env);
		env = unsetenva(a, a->separ, env);
		get_cd(env, a, pwd, real_pwd);
		geta_pwd(a, a->separ);
		get_env(env, a->separ, a);
		history_command(a, a->separ, env);
		execvee(a, a->separ, env);
	}
	return (env);
}

char	**semicolon(char **env, char **pwd, list_t *a, char *real_pwd)
{
	if (a->left == NULL || a->right == NULL)
		return (env);
	if (create_separ(a->left) == 1)
		env = comands_options(env, pwd, a->left, real_pwd);
	if (create_separ(a->right) == 1)
		if ((my_strcmp(a->name, "&&") == 1 && a->left->truee == 1) ||
		(my_strcmp(a->name, "||") == 1 && a->left->truee == 0) ||
		my_strcmp(a->name, ";"))
			env = comands_options(env, pwd, a->right, real_pwd);
	return (env);
}

char	**options(char **env, char **pwd, list_t *a, char *real_pwd)
{
	int	i = 1;

	if (my_strcmp(a->name, ">") == 1)
		i = change_fd(a, 1);
	else if (my_strcmp(a->name, ">>") == 1)
		i = change_fd(a, 2);
	else if (my_strcmp(a->name, "<") == 1)
		i = change_fd_not_create(a, a->name);
	else if (my_strcmp(a->name, "<<") == 1)
		i = double_input_redirection(a);
	else if (my_strcmp(a->name, "|") == 1)
		i = pipe_stuff(env, pwd, a, real_pwd);
	else if (my_strcmp(a->name, ";") == 1 || my_strcmp(a->name, "&&") == 1
		|| my_strcmp(a->name, "||") == 1) {
		i = 0;
		env = semicolon(env, pwd, a, real_pwd);
	}
	else {
		i = 0;
		if (create_separ(a) == 1)
			env = comands_options(env, pwd, a, real_pwd);
	}
	if (i == 2 && create_separ(a->left) == 1 && create_separ(a->right) == 1)
		env = loop_pipe(env, pwd, a, real_pwd);
	if (i == 1 && create_separ(a->left) == 1)
		env = comands_options(env, pwd, a->left, real_pwd);
	return (env);
}
