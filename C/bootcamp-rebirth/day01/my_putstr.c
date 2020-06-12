/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** putstr rebirth
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}	

void	my_putstr(char *c)
{
	int	i;

	i = 0;
	
	while (c[i] !='\0')
	{
		my_putchar(c[i]);
		i++;
	}
}

	
