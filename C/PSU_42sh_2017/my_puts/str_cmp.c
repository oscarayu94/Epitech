/*
** EPITECH PROJECT, 2018
** str_cmp
** File description:
** BY PETER GEORGHE JULCA RUIZ
*/

#include "../list.h"

int	my_strcmpe(char *pwd, char *line)
{
	int	i;

	for (i = 0; pwd[i] != '\0'; i++)
		if (pwd[i] != line[i])
			return (0);
	return (1);
}

int	my_strcmp(char *pwd, char *line)
{
	int	i;

	if (line == NULL || pwd == NULL)
		return (0);
	for (i = 0; pwd[i] != '\0'; i++)
		if (pwd[i] != line[i])
			return (0);
	if (line[i] == pwd[i])
		return (1);
	return (0);
}
