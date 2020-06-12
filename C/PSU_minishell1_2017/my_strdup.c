/*
** EPITECH PROJECT, 2018
** my-strdup
** File description:
** made by Oscar ayuso
*/

#include "list.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
	int	i;
	char	*str2;
	
	i = my_strlen(str);
	str2 = malloc(sizeof(char) * (i + 1));
	for (i = 0; str[i] != '\0'; i++)
		str2[i] = str[i];
	str2[i] = '\0';
	return (str2);
}	
