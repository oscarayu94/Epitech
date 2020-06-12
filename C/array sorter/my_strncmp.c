/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** comparison
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	my_strncmp(char *fi, char *se, int co)
{
	int	i;
	int	j;
	int	stahp = 0;
	int	tmp = 0;
	int	filen = strlen(fi);
	int	selen = strlen(se);

	for (i = 0, j = 0; co != filen || co != selen; i++, j++, stahp++){
		if (fi[i] != se[j]) {
			tmp = fi[i] - se[j];
			if (tmp < 0) {
				tmp = tmp * -1;
			}	
			return (tmp);
		}
	}
	return (tmp);
}

int	main(int ac, char **av)
{
	int	cn;

	if (ac < 4)
		return (84);
	else {
		cn = atoi(av[3]);
		printf ("%d\n", my_strncmp(av[1],av[2],cn)); 
	}
	
}
