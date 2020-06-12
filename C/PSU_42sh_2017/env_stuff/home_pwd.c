/*
** EPITECH PROJECT, 2018
** dkd
** File description:
** kdk
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

char	*get_pwd(char **env)
{
	int     i = 0;

	if (env[i][i] < 0 && env[i][i] > 177)
		exit(84);
	for (i = 0; env[i] != NULL; i++) {
		if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
			return (&env[i][4]);
	}
	return (NULL);
}

char	*get_home(char **env)
{
	for (int i = 0; env[i] != NULL; i++) {
		if (env[i][0] == 'H' && env[i][1] == 'O'
		&& env[i][2] == 'M' && env[i][3] == 'E')
			return (&env[i][5]);
	}
	return (NULL);
}

void	print_env(char **env, int fd)
{
	for (int i = 0; env[i] != NULL; i++) {
		my_putstr_with_fd(env[i], fd);
		my_putchar_with_fd('\n', fd);
	}
}

int	get_env(char **env, space_t *a, list_t *b)
{
	if (env == NULL)
		return (0);
	if ((my_strcmp(a->name, "env")) == 1) {
		b->number = 0;
		if (arguments_after(a) != 0)
			my_putstr_error("env: Too many arguments\n");
		else
			print_env(env, b->fd);
	}
	return (0);
}
