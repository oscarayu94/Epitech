/*
** EPITECH PROJECT, 2018
** list
** File description:
*/

#ifndef LIST_H_
#define LIST_H_

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char	**malloca(int size);
void	print_map(char **map, int size);
int	game(char **map, char *caractere, int size);
int	check_win(char **map, int player, int size);
#endif
