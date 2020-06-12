/*
** EPITECH PROJECT, 2018
** Option 1
** File description:
** Option 1 from fasta tool
*/

#include "list.h"

char	**save_letters(char **tab)
{
	int	i = 0;
	int	j = 0;

	while (tab[i] != NULL){
		while (tab[i][j] != '\0'){
			if (tab[i][j] >= 'a' && tab[i][j] <= 'z')
				tab[i][j] = tab[i][j] + 32;
			j++;
		}
		//printf("%s", tab[i]);
		i++;
	}
	return (tab);
}
	//’a’, ’T’, ’t’, ’G’, ’g’, ’C’, ’c’, ’N’ and 'n'
