/*
** EPITECH PROJECT, 2018
** Anagram
** File description:
** Takes two strings as parameters and prints "anagram" if anagram condition is met.
*/

#include <unistd.h>


int	error_msg(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;

	if (str[0] < '65')
		write (2,"Error: Wrong argument\n",23);
	else if (str[0] >= '91' || str[0] <= '96')
		write (2,"Error: Wrong argument\n",23);
	else if (str[0] >= '123')
		write (2,"Error: Wrong argument\n",23);
	else 
		write (1,"Yes\n",5);
}

int	main(int ac, char **av)
{
	char	*a;
	
	error_msg(av[2]);
}	
