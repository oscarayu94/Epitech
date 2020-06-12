/*
** EPITECH PROJECT, 2018
** binary_exercise
** File description:
** exercise for and/or
*/

#include <stdio.h>

int	binary(char *str, char *scr)
{
	int	i = 0;
	int	j = 0;
	int	found = 1;
	
	while (str[i] != '\0' && !found == 1) { 
		found = 0;
		while (scr[j] != '\0' && found == 0) {  
			if (str[i] == scr[j])
				found = 1;
				j++;
		}
		i++;

	}
	printf("%d\n", found);
	return (1);
}
	
int	main(int ac, char **av)
{
	if (ac != 3)
		return (84);
	else
		binary(av[1], av[2]);
}	
