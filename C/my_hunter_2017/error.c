/*
** EPITECH PROJECT, 2018
** error
** File description:
** checks environement
*/

#include "list.h"

int	error(int ac, char **av)
{
	int	count = 0;

	if (ac > 1 && av == NULL)
		return (0);
	for (int i = 0; av[i] != NULL; i++)
		if (my_strcmp(av[i], "DISPLAY") == 1)
			count++;
	if (count == 0)
		return (0);
	return (1);
}
