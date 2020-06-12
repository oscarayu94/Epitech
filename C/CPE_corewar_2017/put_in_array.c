/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/
#include "list.h"

int num_arg(char *str, char let)
{
	int	g;
	int	i = 0;
	
	for (g = 0; str[g] != '\0'; g++)
	{
		if (str[g] != let && str[g + 1] == let)
			i++;
	}
	return (i);
}

char **malloco(int num_ar)
{
	char	**pwd;
	int	fd;

	pwd = malloc(sizeof(char *) * (num_ar + 6));
	for (fd = 0; fd < num_ar + 6; fd++)
		pwd[fd] = malloc(sizeof(char) * (30));
	return (pwd);
}

coordinates *feed_p(void)
{
	coordinates	*p;

	p = malloc(sizeof(p));
	p->x = -1;
	p->y = 0;
	return (p);
}
