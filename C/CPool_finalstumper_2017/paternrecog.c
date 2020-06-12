/*
** EPITECH PROJECT, 2017
** rush3
** File description:
** 
*/

#include "include/my.h"

int	patternsimple2(char *str, int col, int lines)
{
        int	i;

	i = 0;
	while (i < (my_strlen(str) - 2))
		{
			if (str[i] != str[i+2])
				return (0);
			i++;
		}
		if (str[i] == '*')
			return (2);
		else if (str[i] == 'B')
			return (345);
		else
			return (0);
}

int	patternsimple(char *str, int col, int lines)
{
	int	i;

	i = 0;
	if (str[i] == 'o' && str[my_strlen(str) - 1] == 'o')
		return (1);
	if (col > 1 && lines == 1)
	{
		while (i < (my_strlen(str) - 2))
		{
			if (str[i] != str[i+1])
				return (0);
			i++;
		}
		if (str[i] == '*')
			return (2);
		else if (str[i] == 'B')
			return (345);
	}
	else if (col == 1 && lines > 1)
		return (patternsimple2(str, col, lines));
}

int	patternrecog(char *str, int col, int lines)
{
	if (str[0] == 'o')
		return (1);
	if (my_strlen(str) == 2)
	{
		if (str[0] == '*')
			return (2);
		else if (str[0] == 'B')
			return (345);
		else
			return (0);
	}
	if (col > 1 && lines > 1)
	{
		if (str[0] == '/')
			return (2);
		else if (str[0] == 'A' && str[col - 1] == 'A' && str[(col + 1) * (lines - 1)] == 'C')
			return (3);
		else if (str[0] == 'A' && str[col - 1] == 'C' && str[(col + 1) * (lines - 1)] == 'A')
			return (4);
		else if (str[0] == 'A' && str[col - 1] == 'C' && str[(col + 1) * (lines - 1)] == 'C')
			return (5);	
	}
	return (patternsimple(str, col, lines));
}
