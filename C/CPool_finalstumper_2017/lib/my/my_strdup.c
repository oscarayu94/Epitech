/*
** EPITECH PROJECT, 2017
** day08
** File description:
** task01
*/
#include <stdlib.h>

char	*my_strdup(char const *src)
{
	char	*str;
	int	i;

	str = malloc(sizeof(char) * my_strlen(src));
	i = 0;
	while (i <= my_strlen(src))
	{
		str[i] = src[i];
		i++;	  
	}
	return (str);
}
