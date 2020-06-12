/*
** EPITECH PROJECT, 2018
** print_tab
** File description:
** print_tab
*/

#include <stdio.h>
#include "list.h"

void	my_print_tab(char **tab)
{
	int	i = 0;

	for(i = 1;tab[i] != NULL;i++){
		my_putstr(tab[i]);
		my_putchar(' ');
	}
	my_putchar('\n');
}
