/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** Adds infinetely
*/

// First we should read the number given as a series of numbers
// but before that we should identify if the input given is a number.
// then we should identify if it's negative or positive

#include <stdio.h>

/*

int	identify_num (char *str)
{
	// my get nbr parte
	   
	   int i;
	   int n;
	   
	   i = 0;
	   n = 0;
  
	   while (str[i] != '\0')
	   {
		if ((str[i] < '0' || str [i] > '9'))
		{
			printf("There must be only numbers in the string\n");
			n = n + str[i] - 48;
			i++;
		}
		else
			return (n);
	   }
	   
}
	   
my get number modificado para operaciones */

int	indent1 (int ac, char **av)
{
	int i;
	int n;
	
	i = 0;
	n = 0;
	while (av[1] != '\0' || av[2] != '\0')
	{
		if ((*av[i] < '0' || *av[i] > '9'))
		{
			printf("There must be only numbers in the string\n");
		}
		else if ((*av[i] > '0' || *av[i] < '9'))
		{ 
			n = n + *av[i] - 48;
		}
		i++;
	}	
}

int	indent2 (int ac, char ***av)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (**av != '\0' || **av != '\0')
	{
		if ((**av[i] < '0' || **av[i] > '9'))
		{
			printf("There must be only numbers in the string\n");
		}
		else if ((**av[i] > '0' || **av[i] < '9'))
		{
			n = n + **av[i] - 48;
		}
		i++;
	}
}
