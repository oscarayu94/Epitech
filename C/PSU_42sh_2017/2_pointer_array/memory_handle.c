/*
** EPITECH PROJECT, 2018
** memory_handle
** File description:
** BY PETER GEORGHE JULCA RUIZ
*/

#include "../list.h"

char    **malloca(int num_ar)
{
	char    **pwd;
	int     fd;

	pwd = malloc(sizeof(char *) * (num_ar + 6));
	if (pwd == NULL)
		exit(84);
	for (fd = 0; fd < num_ar + 6; fd++) {
		pwd[fd] = malloc(sizeof(char) * (30));
		if (pwd[fd] == NULL)
			exit(84);
	}
	return (pwd);
}

void    malloca_free(int num_ar, char **pwd)
{
	for (int fd = 0; fd < num_ar; fd++)
		free(pwd[fd]);
	free(pwd);
}

void    malloca_free_str(char **str)
{
	int     i;

	for (i = 0; str[i] != NULL; i++);
	malloca_free(i, str);
}
