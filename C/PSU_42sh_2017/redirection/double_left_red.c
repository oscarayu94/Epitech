
/*
** EPITECH PROJECT, 2018
** minishel2
** File description:
** by prip;
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

char	*delete_next_line(char *b)
{
	for (int i = 0; b[i] != '\0'; i++) {
		if (b[i] == '\n')
			b[i] = '\0';
	}
	return (b);
}

int	child_options(int fd, char *name)
{
	char	*line = NULL;
	char	*buf;

	buf = malloc(sizeof(char) * 1);
	while (my_strcmp(name, line) != 1) {
		my_putstr("? ");
		line = get_input();
		if (line == NULL)
			return (0);
		for (int g = 0; line[g] != '\0'; g++) {
			buf[0] = line[g];
			write(fd, buf, 1);
		}
		line = delete_next_line(line);
	}
	kill(getpid(), SIGUSR1);
	free (buf);
	return (1);
}

int	loop_double_input(list_t *a, char *name)
{
	int	pipefd[2];
	int	pid;
	int	status = 0;
	int	mem = dup(0);

	pipe(pipefd);
	pid = fork();
	if (pid == -1)
		exit(84);
	else if (pid == 0) {
		child_options(pipefd[1], name);
		close(pipefd[0]);
	}
	else {
		waitpid(pid, &status, 0);
		close(pipefd[1]);
		if (dup2(0, mem) == -1)
			my_putstr_error("Error with dup2");
	}
	return (0);
}

int	double_input_redirection(list_t *a)
{
	if (a->left == NULL || a->right == NULL || a->right->name == NULL) {
		my_putstr_error("Missing name for redirect\n");
		return (0);
	}
	else
		loop_double_input(a, a->right->name);
	return (1);
}

