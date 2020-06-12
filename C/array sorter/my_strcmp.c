/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include <stdio.h>

int	my_strcmp(char *fi, char *se)
{
	int	i;
	int	j;
	int	tmp = 0;
	
	for (i = 0, j = 0; fi[i] != '\0'; i++, j++)
		if (fi[i] != se[j]) {
			tmp = fi[i] - se[j];
//			if (tmp < 0) {
//				tmp = tmp * -1;
//			}
			return (tmp);
		}
}


