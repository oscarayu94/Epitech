/*
** EPITECH PROJECT, 2018
** str_to_word
** File description:
** str_to_word
*/

#include <stdio.h>
#include <stdlib.h>

char	**my_str_to_word_array(char *str, char separator)
{
	int	i = 0;
	int	count = 2;
	int	d = 0;
	int	c = 0;
	char	**tab;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == separator)
			count++;
	}
	tab = malloc(sizeof(char*) * count);
	for ( i = 0; str[i] != '\0'; i++)
	{
		d++;
		if (str[i] == separator)
		{
			tab[c] = malloc(sizeof(char) * d);
			d = 0;
			c++;
		}	
	}
	if (d > 0){
		tab[c] = malloc(sizeof(char) * ++d );
		c++;
		d = 0;
	}
	tab[c] = NULL;
	c = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		
		tab[c][d] = str[i];
		d++;
		if (str[i] == separator)
		{
			tab[c][d] = '\0';
			c++;
			d = 0;
		}
		
	}
	return(tab);
}
