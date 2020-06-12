/*
** EPITECH PROJECT, 2018
** helping_functions
** File description:
** oscar ayuso
*/

#include <unistd.h>
#include "list.h"

void	my_putchar(char c)
{
	write (1,&c,1);
}

int	my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return(0);
}			
		
	
	
	       
       
	
