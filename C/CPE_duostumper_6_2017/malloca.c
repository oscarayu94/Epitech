/*
** EPITECH PROJECT, 2018
** tica
** File description:
** malloca
*/

#include "list.h"

char	**malloca(int size)
{
	char	**map;
	int	i;
	
	map = malloc(sizeof(char *) * (size + 2));
	for (i = 0; i < (size + 2); i++)
		map[i] = malloc(sizeof(char) * (size + 6));
	return (map);
}
