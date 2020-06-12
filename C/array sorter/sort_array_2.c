/*
** EPITECH PROJECT, 2018
** sort_array 2.0
** File description:
** Improved version of the sort array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"

char	**sort_array(char **av)
{
	char	*str;
	int	cont = 1;
	int	iter;
	int	iter2;
	char	base = 'a';
	
	while ( av[cont] != NULL)
	{
		if (av[cont + 1] != NULL)
		{
			if (my_strcmp(av[cont], av[cont + 1]) > 0)
			{
				my_swamp(av[cont], av[cont + 1]);
				cont = 0;
			}
		}
		cont++;
	}
	return (av);
}	

int	main(int ac, char **av)
{
	int	i = 0;
	char	*h = "-h";
	char	*help = "--help";
	
	if (ac == 1)
	{
		write(1,"Type -h or --help to see available options\n",43);
	}
	if (ac == 2)
	{
		if (my_strcmp(av[1],h) == 0 || my_strcmp(av[1], help) == 0)
		{
			printf("-----------------------------------------------------\n");
			printf("Alphabetic sorting program made by Oscarium III\n");
			printf("To make proper use of it, input the words you want to sort, separated by a single space.\n");
			printf("It is not case sensitive\n");
			printf("i.e : ./Sortie trex trax\n");
			printf("-----------------------------------------------------\n");
		}	
		else
			write (1, "Wrong input\n",12);
	}	
	else if (ac >= 3)
	{
		sort_array(av);
		print_tab(av);
	}	
	return (0);
}	
