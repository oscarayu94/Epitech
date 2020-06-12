/*
** EPITECH PROJECT, 2018
** requirement
** File description:
** requirement
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	**my_str_to_word_array(char *str, char separator)
{
	int	i = 0;
	int	count = 2;
	int	d = 0;
	int	c = 0;
	char	**tab;

	for (i = 0; str[i] != '\0'; i++){
		if (str[i] == separator)
			count++;
	}
	tab = malloc(sizeof(char*) * count);
	for ( i = 0; str[i] != '\0'; i++){
		d++;
		if (str[i] == separator){
			tab[c] = malloc(sizeof(char) * d);
			d = 0;
			c++;
		}	
	}
	if (d > 0){
		tab[c] = malloc(sizeof(char) * ++d );
		c++;
		d = 0;
	}
	tab[c] = NULL;
	c = 0;
	for (i = 0; str[i] != '\0'; i++){
		tab[c][d] = str[i];
		d++;
		if (str[i] == separator){
			tab[c][d] = '\0';
			c++;
			d = 0;
		}
	}
	return(tab);
}


char	*my_str_concatenate(char *str, char *scr)
{
	char	*sjr;
	int	i = 0;
	int	j = 0;

	sjr = malloc(sizeof(char) * (strlen(str) + strlen(scr) + 1));
	while (str[i] != ':' && str[i] != '\0'){
		sjr[i] = str[i];
		i++;
	}
	sjr[i] = '/';
	i++;
	while (scr[j] != '\0'){
		sjr[i] = scr[j];
		i++;
		j++;
	}
	return (sjr);
}	

char	**get_path(void)
{
	char *path = NULL;
	char **tab_path = NULL;
	
	path = getenv("PATH");
	tab_path = my_str_to_word_array(path, ':');
	return (tab_path);
}

void	fuse_instructions(void)
{
	char	**tab_path = get_path();
	int	i;
	char	**inst = NULL;
	char	*order;

	inst = malloc(sizeof(char *) * 2);
	for (i = 0; tab_path[i + 1] != NULL; i++)
	{
		order = my_str_concatenate(tab_path[i], "ps");
		inst[0] = strdup(order);
		execve(order, inst, NULL);
	}
}

void	my_ps_synthesis(void)
{
	pid_t	pid;
	int	stat = 0;
	int	g = 0;

	if (g != 1)
	{
		pid = fork();
		if (pid > 0)
			pid = waitpid(pid, &stat, 0);
		if (pid == 0){
			fuse_instructions();
			exit(0);
		}
	}
}
	
