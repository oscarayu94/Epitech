/*
** EPITECH PROJECT, 2018
** str_handle
** File description:
** BY PETER GEORGHE JULCA RUIZ
*/

#include "../list.h"

char	*delete_enter(char *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i++);
	if (str[i - 1] == '\n')
		str[i - 1] = '\0';
	return (str);
}

int	my_strlen(char *pwd)
{
	int	i;

	for (i = 0; pwd[i] != '\0'; i++);
	return (i);
}

char	*my_strstr(char *pwd, char *line)
{
	int	i;
	int	g;
	char	*result;

	i = my_strlen(pwd);
	g = my_strlen(line);
	result = malloc(sizeof(char) * (i + g + 2));
	for (i = 0; pwd[i] != '\0'; i++)
		result[i] = pwd[i];
	for (g = 0; line[g] != '\0'; g++) {
		result[i] = line[g];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*my_strcat(char *dest, char *src)
{
	int	i;
	int	o = my_strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
		dest[i + o] = src[i];
	dest[i + o] = '\0';
	return (dest);
}

int	size_array(char **env)
{
	int     i;

	for (i = 0; env[i] != NULL; i++);
	return (i);
}

