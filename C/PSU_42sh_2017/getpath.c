/*
** EPITECH PROJECT, 2018
** getpath
** File description:
** BY PETER GEORGHE JULCA RUIZ
*/

#include "list.h"

char	**getpath(char **env)
{
	int	i;
	char	**path;

	for (i = 0; env[i] != NULL; i++)
	{
		if (env[i][0] == 'P' && env[i][1] == 'A'
		&& env[i][2] == 'T' && env[i][3] == 'H') {
			path = get_path_array(&env[i][5], ':');
			return (path);
		}
	}
	return (NULL);
}
