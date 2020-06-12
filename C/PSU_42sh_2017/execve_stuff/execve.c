/*
** EPITECH PROJECT, 2018
** minishel
** File description:
** by oriol
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"
#include <sys/types.h>
#include <sys/wait.h>

char	**path_ls(char **path, char *str)
{
	str = my_strstr("/", str);
	for (int i = 0; path[i] != NULL; i++)
		path[i] = my_strstr(path[i], str);
	return (path);
}

char	**put_comands(char *path, space_t *a)
{
	int	i = 1;
	char	**av;

	av = malloca(7);
	av[0] = copy(path);
	while (a != NULL && my_strcmp(a->name, ";") != 1 &&
	my_strcmp(a->name, ">") != 1 &&
	my_strcmp(a->name, ">>") != 1 &&
	my_strcmp(a->name, "<<") != 1 &&
	my_strcmp(a->name, "<") != 1 &&
	my_strcmp(a->name, "|") != 1) {
		av[i] = copy(a->name);
		i++;
		a = a->next;
	}
	av[i] = NULL;
	return (av);
}

int	ls_loop(list_t *b, space_t *a, char **env)
{
	pid_t	child_pid;
	int	status = 0;
	int	waitoptions = 0;

	child_pid = fork();
	if (child_pid == -1)
		exit(84);
	if (child_pid == 0) {
		execute(b, a, env);
		close((b)->fd);
		exit(0);
	}
	if (child_pid > 0)
		child_pid = waitpid(child_pid, &status, waitoptions);
	return (0);
}
