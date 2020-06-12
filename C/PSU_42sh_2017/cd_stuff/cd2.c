/*
** EPITECH PROJECT, 2018
** dehosl
** File description:
** dedede
*/

#include "../list.h"

char	*root(char *result)
{
	if (result[0] == '\0') {
		result[0] = '\\';
		result[1] = '\0';
	}
	return (result);
}

void	previous_dir(char **pwd)
{
	int	i;
	int	g;
	char	*result;

	g = my_strlen(*pwd);
	while ((*pwd)[g] != '/')
		g--;
	result = malloc(sizeof(char) * (g + 2));
	if (g != 0)
		(*pwd)[g] = '\0';
	else
		(*pwd)[g + 1] = '\0';
	for (i = 0; (*pwd)[i] != '\0'; i++)
		result[i] = (*pwd)[i];
	result[i] = '\0';
	result = root(result);
	*pwd = result;
}
