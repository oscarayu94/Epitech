/*
** EPITECH PROJECT, 2018
** str_concatenate
** File description:
** concatenates two strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*my_str_concatenate( char *str, char *scr)
{
	char	*sjr;
	int	i = 0;
	int	j = 0;
	
	sjr = malloc(sizeof(char) * (strlen(str) + strlen(scr) + 1));
	while (str[i] != ':' && str[i] != '\0')	//El separador ha sido cambiado para el path
	{
		sjr[i] = str[i];
		i++;
	}
	sjr[i] = '/';
	i++;	
	while (scr[j] != '\0')
	{
		sjr[i] = scr[j];
		i++;
		j++;
	}
	return (sjr);
}

	
		
