/*
** EPITECH PROJECT, 2018
** main
** File description:
** Made by oscar ayuso
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>

char	**maze_imperfect(char *cor_x, char *cor_y)
{
	int i;
	int j;
	int x = atoi(cor_x);
	int y = atoi(cor_y);
	char **imperfect = NULL;
	
	imperfect = malloc(sizeof(char *) * (y + 1));
	for (i = 0; i != y; i++)
		imperfect[i] = malloc(sizeof(char) * (x + 1));
	for (i = 0; imperfect[i] != NULL; i++) {
		for (j = 0; j != x; j++)
			imperfect[i][j] = 'X';
	}
	for (i = 1; imperfect[i + 1] != NULL; i++) {
		for (j = 1; j != x - 1; j++)
			imperfect[i][j] = 'X';
	}
	tab(imperfect, y, x);
	my_print_tab(imperfect);
	return (imperfect);
}	

char	**maze_perfect(char *cor_x, char *cor_y)
{
	int i;
	int j;
	int x = atoi(cor_x);
	int y = atoi(cor_y);
	char **perfect = NULL;

	perfect = malloc(sizeof(char *) * y + 1);
	for (i = 0; i != y; i++)
		perfect[i] = malloc(sizeof(char) * x + 1);
	for (i = 0; perfect[i] != NULL; i++) {
		for (j = 0; j != x; j++) 
			perfect[i][j] = 'X';
	}
	for (i = 1; perfect[i + 1] != NULL; i++) {
		for (j = 1; j != x - 1; j++)
			perfect[i][j] = 'X';
	}			
	my_print_tab(perfect);			
	return (perfect);
}

int	main(int ac, char **av)
{
	srand(time(NULL));
	if (ac < 3) {
		my_putstr("Wrong input\n");
		return (84);
	}
	if (ac == 3)
		maze_imperfect(av[1],av[2]);
	if (ac == 4) {
		if (my_strcmp(av[3], "[perfect]") == 0)
			maze_perfect(av[1], av[2]);
		else
			return(84);
	}	
	if (ac > 4)
		return(84);
}

		
