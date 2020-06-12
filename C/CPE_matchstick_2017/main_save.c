/*
** EPITECH PROJECT, 2018
** main of matchstick
** File description:
** matchstick main
*/

//read, write, malloc, free, time, getpid, random, srandom.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "list.h"

char	**create_map_game(void)
{
	char	**tab;
	int	i = 7;
	
	tab = malloc(sizeof(char *) * 7);
	
	//bucle para llenar malloc
	
	for (i = 0; i != 6; i++)
		tab[i] = malloc(sizeof(char) * 10);
	
	tab[0] = "*********\n";
	tab[1] = "*   |   *\n"; 	
	tab[2] = "*  |||  *\n";
	tab[3] = "* ||||| *\n";
	tab[4] = "*|||||||*\n";
	tab[5] = "*********\n";
	tab[6] = NULL;
	
	return (tab);
}

char	print_game_board(char **tab)
{
	int s = 0;
	
	while (tab[s] != NULL)
	{
		my_putstr(tab[s]);
		s++;
	}
}

char	**update_board_game(int line, int nb_matches, char **tab)
{	
	int c = 0;
	int i = 1;
	int count = 0;
	int rslt = 0;

	while (tab[line][i] != '*') {
		i++;
		while (tab[line][i] == '|')
			count++;
		rslt = count - nb_matches;
	}
	while (tab[line][rslt] != '*') {
		printf("%s\n", tab[c]);
		tab[c][rslt] = ' ';
		rslt++;
	}
	return (tab);	

	//bucle que imprime hasta llegar a una cantidad X.
}	

int	main(int ac, char **av)
{
	int l;
	int mt;
	char **pepi;
	char **pepi2;
	
	pepi = create_map_game();
	pepi2 = update_board_game(l,mt,pepi);
		
	if (ac != 3)
		exit(84);
	create_map_game();
	print_game_board(pepi);
	l = my_getnbr(av[1]);
	mt = my_getnbr(av[2]);
/*	printf("%d\n",l);
	printf("%d\n",mt); */
        update_board_game(l,mt,pepi);
	print_game_board(pepi2);
}

