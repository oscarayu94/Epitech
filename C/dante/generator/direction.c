/*
** EPITECH PROJECT, 2018
** direction
** File description:
** does movement based on ramdom number
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char	**tab(char **tab, int ver, int hor)
{
	int	a = rand() % 4;
	int	x = 1;
	int	y = 1;

	
	while ( x < (hor-1) || y < (ver-1) )
	{
		a = rand() % 4;
		//printf("This is a: %d\n", a);
		//printf("This is x: %d\n", x);
		//printf("This is y: %d\n", y);
		//my_print_tab(tab);
		//printf("\n ------------ \n");
		if (a == 0 && x > 0){
			x--;
			tab[x][y] = '*';
		}	
		if (a == 1 && y < (hor - 1)){
			y++;
			tab[x][y] = '*';
		}	
		if (a == 2 && x < (ver - 1)){
			x++;
			tab[x][y] = '*';
		}	
		if (a == 3 && y > 0){
			y--;
			tab[x][y] = '*';
		}
	}
	return (tab);
} 	
