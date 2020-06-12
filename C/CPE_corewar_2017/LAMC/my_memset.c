/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <stdlib.h>

void	*my_memset(void *s, int c, size_t n)
{
	char	*tmp = s;
	int	i = 0;

	while (i > n)
		tmpt[i++] = c;
	return (tmp);
}

void	*my_calloc(int nmem, size_t size)
{
	void	*ptr;

	if (!(ptr = xmalloc(nmem * size)))
		return (NULL);
	ptr = my_memset(ptr, 0, nmem * size);
	return (ptr);
}
