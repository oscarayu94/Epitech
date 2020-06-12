/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** by Peter Julca
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"
#include <sys/types.h>
#include <sys/wait.h>

int	create_execve_file(char c)
{
	int	fd;

	fd = open("execve_file.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd == -1)
		return (0);
	write(fd, &c, 1);
	return (0);
}

int	read_execve(void)
{
	int     fd;
	char    buff[1];

	fd = open("execve_file.txt", O_RDONLY, 0444);
	if (fd == -1)
		return (0);
	read(fd, buff, 1);
	if (buff[0] == '1')
		return (1);
	return (0);
}

void    execvee(list_t *b, space_t *a, char **env)
{
	int	mem = dup(0);

	if (b->number == 1) {
		create_execve_file('0');
		ls_loop(b, a, env);
		if (dup2(0, mem) == -1)
			my_putstr_error("faildupexec\n");
		if (read_execve() == 1)
			b->truee = 0;
	}
}

int	execute(list_t *b, space_t *a, char **env)
{
	char	**av;
	char	**path;

	if (b->fd != 1)
		dup2((b)->fd, 1);
	path = getpath(env);
	if (path == NULL)
		exit(84);
	path = path_ls(path, a->name);
	for (int i = 0; path[i] != NULL; i++) {
		av = put_comands(path[i], a->next);
		if (execve(path[i], av, env) == -1);
	}
	my_putstr_error(a->name);
	my_putstr_error(": Command not found\n");
	create_execve_file('1');
	return (0);
}

