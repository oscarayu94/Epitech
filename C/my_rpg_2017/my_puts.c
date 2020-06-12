/*
** EPITECH PROJECT, 2017
** my_put_everything
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "list.h"

int	my_strlen(char *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}

int     my_strcmp(char *pwd, char *line)
{
	int	i;

	for (i = 0; line[i] != '\0' && pwd[i] != '\0'; i++)
		if(pwd[i] != line[i])
			return (0);
	return (1);
}

