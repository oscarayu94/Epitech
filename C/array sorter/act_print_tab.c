/*
** EPITECH PROJECT, 2018
** act_print_tab
** File description:
** adapated print tab for sort array 2
*/

#include <stdio.h>

int	print_tab(char **tab)
{
	int	i;

	for (i = 1; tab[i] != NULL; i++)
	{
		printf ("%s", tab[i]);
		printf("\n");
	}
}	
       
