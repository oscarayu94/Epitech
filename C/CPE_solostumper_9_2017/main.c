/*
** EPITECH PROJECT, 2018
** main plaindorme
** File description:
** main
*/

#include "list.h"
#include <unistd.h>

int	look_string(char *str)
{
	int	i = 0;
	int	j = my_strlen(str) - 1;

	if (j == -1){
		my_putstr("not a palindrome.\n");
		return(0);
	}	
	for(i = i , j = j;str[i] != '\0';i++ , j--){	
		if(str[j] != str[i] && str[j] + 32 != str[i] && str[j] - 32 != str[i]){
			my_putstr("not a palindrome.\n");
			return(0);
		}	
	}
	my_putstr("palindrome!\n");
	return(0);
}	

int	main(int ac, char **av)
{
	if(av[1] == NULL){
		write(0 , "Error: missing arguments.\n" , 26); 
		return(84);
	}
	if(ac == 2)
		look_string(av[1]);
}	
