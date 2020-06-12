/*
** EPITECH PROJECT, 2018
** hidenp
** File description:
** Made by Oscar Ayuso
*/

#include "list.h"
#include <stdio.h>

int	new_check(char *str, char *scr)
{
	int	i = 0;
	int	j = 0;
	int	match = 2;
		
	while (str[i] != '\0' && match != 0) {
		match = 0;
		for (j = j; scr[j] != '\0' && match != 1; j++) {
			if (str[i] == scr[j]) {
				match = 1;
                        }
		}
		i++;
	}
	if (match == 0) {
		my_putstr("0\n");
		return (0);
	}	
	else
		my_putstr("1\n");
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return(84);
	else
		new_check(av[1], av[2]);
}	


	
