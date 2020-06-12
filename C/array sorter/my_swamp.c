/*
** EPITECH PROJECT, 2018
** my_swamp
** File description:
** Swaps two pointers, shreks them up.
*/

#include <stdlib.h> 
#include <string.h>

void	my_swamp(char *str, char *str2)
{
	char	*tmp = (char *)malloc((strlen(str) + 1) *sizeof(char));
	strcpy(tmp, str);
	strcpy(str, str2);
	strcpy(str2, tmp);
	free(tmp);
}
