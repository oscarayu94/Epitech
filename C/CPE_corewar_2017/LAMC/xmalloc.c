/*
** EPITECH PROJECT, 2018
** xmalloc
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <stdlib.h>

void	*xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		return (ptr);
	return (NULL);
}
