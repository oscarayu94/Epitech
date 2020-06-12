/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** main of the matchstick
*/

#include "list.h"
#include <stdlib.h>

int	check_arg(char *str)
{
	int	c = 0;

	while (str[c] != '\0') {
		if (str[c] < '0' || str[c] > '9')
			return (0);
		c++;
	}
	return (1);
}

char	**malloc_board(int lines)
{
	char	**tab;
	int	i;
	int	ch = 0;

	ch = (lines *2) + 2;
	tab = malloc(sizeof(char*) * (lines + 1));
	for (i = 0; i <= lines + 1; i++)
	{
		tab[i] = malloc(sizeof(char) * (ch) + 1);
	}
	//igualar tab de 0 a esta funcion?
	first_last_line(tab, lines);
	return(tab);
}

char	**first_last_line(char **tab, int lines)
{
	char	*str;
	int	i; 
	int	j;
	
	// usar contadopr [i][j]
	for (i = 1; i < (lines * 2) + 1; j++)
			tab[i][j] = '*';
	tab[i][j] = '\n';
	tab[i][j + 1]  = '\0';
	return (tab);
}

char	*borders(char **tab, int lines)
{
	int	i;
	int	j;

	j = 0;
	
	for	(i = 0; i < lines + 2; i++)
	{
		if (i > 1)
		{
			tab[i][j] = '*';
			j++;
			for (; j < (lines * 2) + 1; j++)
			{}
			tab[i][j] = '*';
			tab[i][j+1] = '\n';
			tab[i][j+2] = '\0';
		}
	}
	return(tab);
}

char    **print_game_board(char **tab, int lines)
{
	int s = 0;

	while (s <= lines + 1 )
	{
		my_putstr(tab[s]);
		my_putstr("\n");
	        s++;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int	lines;
	int	max_matches;
	char	**tab;
	
	if (ac != 3)
		return (84);
	if (check_arg(av[1]) == 0 || check_arg(av[2]) == 0)
		return (84);
	lines = my_getnbr(av[1]);
	max_matches = my_getnbr(av[2]);
	malloc_board(lines);
	print_game_board(tab, lines);
}
