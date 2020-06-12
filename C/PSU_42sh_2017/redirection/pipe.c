/*
** EPITECH PROJECT, 2018
** pipe_Stuff
** File description:
** by Oriol
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"
#include <sys/types.h>
#include <sys/wait.h>

char	**loop_pipe(char **env, char **pwd, list_t *a, char *real_pwd)
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
		close(pipefd[0]);
		a->left->fd = dup(pipefd[1]);
		comands_options(env, pwd, a->left, real_pwd);
		close(a->left->fd);
		kill(getpid(), SIGUSR1);
		exit(0);
	}
	else {
		waitpid(pid, &status, 0);
		close(pipefd[1]);
		if (dup2(pipefd[0], 0) == -1)
			my_putstr_error("Error with dup2");
		else
			env = comands_options(env, pwd, a->right, real_pwd);
		dup2(mem, 0);
	}
	return (env);
}

int	pipe_stuff(char **env, char **pwd, list_t *a, char *real_pwd)
{
	if (a->left == NULL || a->right == NULL || a->right->name == NULL) {
		my_putstr_error("Invalid null comand.\n");
		return (0);
	}
	return (2);
}
