/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "list.h"

void	display_help()
{
	my_putstr("USAGE\n");
	my_putstr("\t./FASTAtools option\n");
	my_putstr("\n\nDESCRIPTION\n");
	my_putstr("\toption 1: read FASTA from the standar input, write the");
	my_putstr("DNA sequences to the standard output\n\n");
}	

char	**sum_str_tab(char **tab, char *str)
{
	int	i;
	char	**new_tab;

	if (str == NULL || str[0] == '\0' || str[0] == '\n')
		return (tab);
	if (tab == NULL) {
		tab = malloc(sizeof(char*) * 2);
		tab[0] = str;
		tab[1] = NULL;
		return (tab);
	}
	for (i = 0; tab[i] != NULL; i++);
	new_tab = malloc(sizeof(char*) * (i + 2));
	for (i = 0; tab[i] != NULL; i++)
		new_tab[i] = tab[i];
	tab[i] = str;
	tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}
	
char	**read_fasta()
{
	char	**tab = NULL;
	char	*str = NULL;
	char	*line = NULL;
	size_t	len = 0;
	int	i = 0;

	while ((getline(&line, &len, stdin) != -1)){
		str = strdup(line);
		printf("%s", str);
		sum_str_tab(tab, str);
		i++;
	}
       	return(tab);
}	
	
void	read_options(char **tab)
{
	if (my_strcmp(tab[1],"-h") == 0)
		display_help();
	if (my_strcmp(tab[1],"1") == 0)
		read_fasta();
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (84);
	else
		read_options(av);
}	
