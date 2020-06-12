/*
** EPITECH PROJECT, 2018
** test the condicione
** File description:
** Oscar Ayuso
*/

#include <stdio.h>

int	test(char *cond, char *str, char *scr)
{
	int	c = 0;
	int	j = 0;
	int	ok = 0;

	if (cond[c] == '1') {
		while (scr[j] != '\0' && ok == 1) {
			printf ("1\n");
                        j++;
		}
	}
	return (0);
}	

int	main(int ac, char **av)
{
	if (ac != 4)
		return(84);
	else
		test(av[1], av[2], av[3]);
}	
