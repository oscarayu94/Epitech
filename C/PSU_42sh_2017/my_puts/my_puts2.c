/*
** EPITECH PROJECT, 2018
** minishel
** File description:
** by oriol
*/

#include "../list.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (1);
}

int	my_putstr_error(char *str)
{
	int     i = 0;

	while (str[i] != '\0') {
		write(2, &str[i], 1);
		i = i + 1;
	}
	return (0);
}

char	*copy(char *pwd)
{
	char    *av;
	int     i;

	for (i = 0; pwd[i] != '\0'; i++);
	av = malloc(sizeof(char) * i + 1);
	for (i = 0; pwd[i] != '\0'; i++)
		av[i] = pwd[i];
	av[i] = '\0';
	return (av);
}
