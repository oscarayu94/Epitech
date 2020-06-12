/*
** EPITECH PROJECT, 2018
** Tic Tac Toe
** File description:
** Main
*/

#include "list.h"

int	create_map(char **map, int size)
{
	int	i = 1;
	int	y;
	
	map[0][0] = '+';
	map[0][size + 1] = '+';
	map[size + 1][0] = '+';
	map[size + 1][size + 1] = '+';
	map[0][size + 2] = '\n';
	map[size + 1][size + 2] = '\n';
	while (i <= size) {
		map[i][0] = '|';
		for (y = 1; y <= size; y++)
			map[i][y] = ' ';
		map[i][size + 1] = '|';
		map[i][size + 2] = '\n';
		map[0][i] = '-';
		map[size + 1][i] = '-';
		i++;
	}
	return (0);
}

int	display_field(char **av, char *caractere, int size)
{
	char	**map;
	
	map = malloca(size);
	create_map(map, size);
	print_map(map, size);
	game(map, caractere, size);
	return (0);
}

int	flag(char **av, char *caractere, int ac)
{
	int	size = 3;
	
	caractere[0] = 'X';
	caractere[1] = 'O';
	if (ac > 2){
		if (strcmp(av[1], "-p1") == 0)
		        caractere[0] = av[2][0];
	}
	if (ac > 4) {
		if (strcmp(av[3], "-p2") == 0)
	        	caractere[1] = av[4][0];
	}
	if (ac > 6) {
		if (strcmp(av[5], "-s") == 0)
	        	size = atoi(av[6]);
	}
	else if (ac > 2) {
		if (strcmp(av[1], "-s") == 0)
	        	size = atoi(av[2]);
	}
	return (size);
}

int	main(int ac, char **av)
{
	char	caractere[2];
	int	size;
	
	size = flag(av, caractere, ac);
	display_field(av, caractere, size);
}
