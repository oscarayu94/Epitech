/*
** EPITECH PROJECT, 2018
** count_words
** File description:
** count words rebirth
*/

#include <stdio.h>
#include "list.h"

int	count_words(char *str)
{
	int	i = 0;
	int	j = 0;
	char	*c = "count_words: String pointer is NULL";

	if (str == NULL)
		rb_xerror(c);
	while (str[i] != '\0')	{
		if ((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')) {
			j++;
			while ((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))
				i++;
		}
		else
			i++;
	}
	return (j);
}
