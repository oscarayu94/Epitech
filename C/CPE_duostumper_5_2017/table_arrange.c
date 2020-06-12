/*
** EPITECH PROJECT, 2018
** table_arrange
** File description:
** arranges the value table
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	**table_arrange(char **tab)
{
	int	i;
	int	j;
	int	o = 0;
	int	k = 2;
	int	m = 0;
	int	warning = 0;
	char	*memorize = NULL;
	char	**new_tab;
	
	while (tab[i] != NULL)
		i++;
	memorize = malloc(sizeof(char) * (i * 2));
	new_tab = malloc(sizeof(char*) * i);
	while (tab[o] != NULL){
		for (i = 0, j = 2; tab[i] != NULL; i++){
			if (tab[o][k] == tab[i][j]){
				memorize[m] = tab[i][j - 2];
				m++;
				memorize[m] = ',';
				m++;
				warning = 1;
			}
		if (warning == 1){
			new_tab[i] = malloc(sizeof(char) * strlen(memorize));
			new_tab[i] = memorize;
			m = 0;
		}	
		else if (warning == 0){
				new_tab[i] = malloc(sizeof(char) * strlen(tab[i]));
				new_tab[i] = tab[i];
			}	
		}
		o++;
	}
	for (i = 0; new_tab != NULL; i++)
		printf("%s\n",new_tab[i]);
	return (new_tab);
}

int main(int ac, char **av)
{
	int i = 0;
	char **tab = NULL;

	tab = malloc(sizeof(char *) * (7));
	tab[7] = NULL;	     
	for ( i = 0;tab[i] != NULL; i++)
		tab[i] = malloc(sizeof(char) * 4);
	tab[0] = "f:3\0";
	tab[1] = "b:1\0";
	tab[2] = "a:2\0";
	tab[3] = "c:1\0";
	tab[4] = "d:1\0";
	tab[5] = "e:1\0";
	table_arrange(tab);
}	
