/*
** EPITECH PROJECT, 2018
** tictactoe
** File description:
** check
*/

#include "list.h"

int	check_horizontal(char *str, int size)
{
	int	y;
	int	nb = 0;
	
	for (y = 1; y < size; y++){
		if (str[y] == str[y + 1] && str[y] != ' ')
			nb++;
		if (nb == (size - 1))
			return (1);
	}
	return (0);
}

int	check_vertical(char **map, int size)
{
	int	i;
	int	y;
	int	nb = 0;
	
	for (i = 1; i <= size; i++){
		for (y = 1; y <= size; y++){
			if (map[y][i] == map[y + 1][i] && map[y][i] != ' ')
				nb++;
			if (nb == (size - 1))
			        return (1);
		}
	}	
	return (0);
}

int	check_diagonal(char **map, int size)
{
	int	i;
	int	y;
	int	x;
	int	nb1 = 0;
	int	nb2 = 0;
	
	for (i = 1; i < size; i++){
		for (y = 1; y <= size; y++){
			if (map[i][y + i - 1] == map[i + 1][y + i] && map[i][y + i - 1] != ' ')
				nb1++;
			if (nb1 == (size - 1))
			        return (1);
		}
		for (x = size; x >= 1; x--){
			if (map[i][x - i + 1] == map[i + 1][x - i] &&
			    map[i][x - i + 1] != ' ' && map[i][x - i + 1] != ' ')
				nb2++;
			if (nb2 == (size - 1))
	        		return (1);
		}
	}
	return (0);
}

int	check_win(char **map, int player, int size)
{
	int	i;

	for (i = 1; i <= size; i++){
		if (check_horizontal(map[i], size) == 1) 
			return (1);
       	}
        if (check_vertical(map, size) == 1 || check_diagonal(map, size))
		return (1);
	return (0);
}
