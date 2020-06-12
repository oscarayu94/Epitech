/*
** EPITECH PROJECT, 2018
** A rebuilding of minishell.
** File description:
** Made by Oscar Ayuso
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "list.h"

char	**get_path(char **envi)
{
	int	i;
	char	**path = NULL;

	for (i = 0; envi[i] != NULL; i++) {
		if (my_strcmp("PATH=", envi[i]) == 0) {
                        path = my_str_to_word_array(&envi[i][5],':');
                }
	}
	return (path);
}

int	separate_buildins(char **tabx, char **env)
{
	int	i;
	
	for ( i = 0; tabx[i] != NULL; i++)
	{
		if ((my_strcmp(tabx[i], "exit") == 0) || (my_strcmp(tabx[i], "cd\n") == 0) 
		    || (my_strcmp(tabx[i], "setenv\n") == 0)
		    || (my_strcmp(tabx[i], "unsetenv\n") == 0) || (my_strcmp(tabx[i], "env\n") == 0))
			{
				decide_instructions(tabx, env);
				return (1);
			}
		else
			return(0);
	}
	return(0);
}

void	fuse_instructions(char *line, char **path, char **env, char **tabx)
{
	int	i;
	char	*order;
	char	*cmd;

	cmd = my_strdup(tabx[0]);
	for ( i = 0; path[i + 1] != NULL; i++)
	{	
		order = my_str_concatenate(path[i], cmd);
		tabx[0] = my_strdup(order);
		execve(order,tabx, env);
	}
}	

int	loop_active(char **env)
{
	char	*line = NULL;
	size_t	len = 0;
	char	**tabx = NULL;
	char	**path = NULL;
	int	i;
	pid_t	pid;
	int	stat = 0;
	
	path = get_path(env);
	while (1)
	{
		my_putstr("$> ");
		getline(&line, &len, stdin);
		i = my_strlen(line);
		line[i - 1] = '\0';
		tabx = my_str_to_wordtab(line);
		if (separate_buildins(tabx, env) != 1)
		{	
			pid = fork();
			if (pid > 0) // Eso significa proceso padre
				pid = waitpid(pid, &stat, 0);
			if (pid	== 0) {	// Eso significa proceso hijo
				fuse_instructions(line, path, env, tabx);
				exit(0);
			}	
		}		
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char **env_cpy = NULL;

	env_cpy = my_tabcpy(env);
	loop_active(env_cpy);
}
