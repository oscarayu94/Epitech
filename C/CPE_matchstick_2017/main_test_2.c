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

char	**create_board(int lines)
{
	char	**tab;
	int	i;
	int	j;
	int	ch= 0;
	int	m;
	
	//caracthers
	ch = (lines * 2) + 1;
	//liberador de lineas.
	tab = malloc(sizeof(char*) * (lines + 1));
	for (i = 0; i <= lines + 1; i++) {
		//liberador de columnas
		tab[i]  = malloc(sizeof(char*) * (ch));
		for (j = 0 ; j < 1; j++) {
			tab[i][j] = '*';
		
			m = (ch/2)-0,5;
			
			for (j = 0; j <= m; j++) {	
				tab [i][j] = ' ';
				printf("%c",tab[i][j]);
			}
			
		}	
	}
	return (tab);
}

char    print_game_board(char **tab, int lines)
{
	int s = 0;

	while (s <= lines + 1 )
	{
		my_putstr(tab[s]);
		my_putstr("\n");
	        s++;
	}
}

int	main(int ac, char **av)
{
	int	lines;
	int	max_matches;
		
	if (ac != 3)
		return (84);
	if (check_arg(av[1]) == 0 || check_arg(av[2]) == 0)
		return (84);
	lines = my_getnbr(av[1]);
	max_matches = my_getnbr(av[2]);
	print_game_board(create_board(lines), lines);
}
