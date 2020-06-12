/*
** EPITECH PROJECT, 2017
** Rush3
** File description:
** rush3
*/
#include "include/my.h"

int     patternrecog(char *str, int col, int lines);

int     countcol(char *str)
{
	int     i;
	
	i = 0;
	while (i < my_strlen(str) && str[i] != '\n')
		i++;
	return (i);
}

int     countlines(char *str)
{
	int     i;
	int     cpt;

	i = 0;
	cpt = 0;
	while (i < my_strlen(str))
	{
		if (str[i] == '\n')
			cpt++;
		i++;
	}
	return (cpt);
}

void	display_name_dim(int col, int lines, int assig)
{
	int	i;

	i = 0;
	if (assig > 5)
	{
		while (i < 2)
		{
			my_putstr("[rush1-");
			if (i == 0)
				my_put_nbr(3);
			else if (i == 1)
				my_put_nbr(4);
        		my_putstr("] ");
			my_put_nbr(col);
			my_putchar(' ');
			my_put_nbr(lines);
			my_putstr(" || ");
		i++;
		}
		assig = assig - 340;
	}
	my_putstr("[rush1-");
	my_put_nbr(assig);
	my_putstr("] ");
	my_put_nbr(col);
	my_putchar(' ');
	my_put_nbr(lines);
	my_putchar('\n');
}

void    rush3(char *str)
{
	int     col;
	int     lines;
	int     assig;

	col = countcol(str);
	lines = countlines(str);
	assig = patternrecog(str, col, lines);
	if (assig > 0)
		display_name_dim(col, lines, assig);
}
