/*
** EPITECH PROJECT, 2018
** StrAndIntHandle
** File description:
** 
*/

#include "list.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char *str)
{
	int	i;

	for(i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return(0);	
}
