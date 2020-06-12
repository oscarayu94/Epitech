/*
** EPITECH PROJECT, 2018
** Main file
** File description:
** Made by Oscar Ayuso
*/

#include <unistd.h>
#include <stdio.h>
#include "list.h"

int	us_name(char *str)
{
	int	i = 0;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	if (count_letters(str) == 2) {
		str = two_letters(str);
		i = 0;
	}
	if (count_letters(str) > 2) {
		str = several_letters(str);
	}	
	if (count_spaces(str) == 1) {
		str = no_middle_letter(str);
	}
	if (count_spaces(str) == 2) {
		str = middle_letter(str);
	}	
	my_putstr(str);
	my_putchar('\n');
	return(0);
}	

int	main(int ac, char **av)
{
	if(ac < 2 || ac > 2)
		return(84);
	else {
		us_name(av[1]);
		return(0);
	}
	return(0);
}
