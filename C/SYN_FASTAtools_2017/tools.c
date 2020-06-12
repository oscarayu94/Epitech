/*
** EPITECH PROJECT, 2018
** tools
** File description:
** A compilation of useful mini-programs alias tools
*/

#include "list.h"

void	my_putchar(char c)
{
	write (1,&c,1);
}

int	my_putstr(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0'){
		my_putchar(str[i]);
		i++;
	}
	return (0);
}	

int	my_strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++){
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}	

void	my_print_tab(char **tab)
{
	int	i = 0;

	for (i = 0; tab[i] != NULL; i++) {
		my_putstr(tab[i]);
		my_putchar('\n');	
	}
}
