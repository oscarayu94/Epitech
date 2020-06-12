/*
** EPITECH PROJECT, 2018
** main
** File description:
** french name formatter main
*/

#include <stdio.h>
#include "list.h"

int	french_formatter(char *str)
{
	int i = 0;
	
	if(str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while(str[i] != '-' || str[i] == ' '){
		i++;
		if(str[i] >= 'A' && str[i] <= 'Z')
		    str[i] = str[i] + 32;
	}
	if(str[i] == '-'){
		if(str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] = str[i + 1] - 32;
	}
	i = i + 2;
	for(i = i;str[i] != ' ';i++){
		if(str[i] >= 'A' && str[i] <= 'Z')
		    str[i] = str[i] + 32;
	}
	for(i = i;str[i] != '\0';i++){
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
       	}	
	my_putstr(str);
	return(0);
}



int	main(int ac, char **av)
{
	if(ac < 2)
		return(84);
	else
		french_formatter(av[1]);
}	
