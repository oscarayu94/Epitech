/*
** EPITECH PROJECT, 2018
** game
** File description:
** tictactoe
*/

#include "list.h"

void	print_map(char **map, int size)
{
	int	i = 0;
	
	for (i = 0; i < (size + 2); i++)
		printf("%s", map[i]);
}

int	put_in_map(char **map, char *caractere, char *line, int player)
{
	int	x;
	int	y;

	x = line[0] - 48;
	y = line[2] - 48;
	map[y + 1][x + 1] = caractere[player - 1];
	return (0);
}

int	user_input(char **map, char *caractere, int player, int size)
{
	char	*line;
	size_t	len = 0;

	getline(&line, &len, stdin);
	if (strlen(line) != 4 || line[1] != ',')
		return (-1);
	else
		put_in_map(map, caractere, line, player);
	return (check_win(map, player, size));
}

int	game(char **map, char *caractere, int size)
{
	int	finish = 0;
	int	turn = 1;
	
	while (finish == 0){
		if (turn == 1){
			printf("Player 1> ");
			finish = user_input(map, caractere, 1, size);
			print_map(map, size);
			if (finish == 1)
				printf("Player 1 won!\n");
			turn++;
		}
		else if (turn == 2){
			printf("Player 2> ");
			finish = user_input(map, caractere, 2, size);
			print_map(map, size);
			if (finish == 1)
				printf("Player 2 won!\n");
			turn--;
		}
	}
	return (0);
}
