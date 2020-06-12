/*
** EPITECH PROJECT, 2018
** input_handle
** File description:
** BY PETER GEORGHE JULCA RUIZ
*/

#include "list.h"
#include "linked_list_stuff/linked_list.h"

char	*get_input(void)
{
	char	*line = NULL;
	size_t	len = 0;
	char	*av;

	if (getline(&line, &len, stdin) == -1) {
		my_putstr("\n");
		exit(0);
	}
	if (line == NULL || line[0] == '\0') {
		av = malloc(sizeof(char) * 2);
		if (av == NULL)
			exit(84);
		av[0] = '\n';
		av[1] = '\0';
		return (av);
	}
	return (line);
}

char	*get_inputs(int stream)
{
	char	*line = NULL;
	size_t	len = 0;

	getline(&line, &len, stdin);
	return (line);
}
