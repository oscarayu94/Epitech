/*
** EPITECH PROJECT, 2018
** built_functions
** File description:
** does some of the nonbuilt function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"

char	**decide_instructions(char **tabx, char **envi)
{
	int	i;
	
	for ( i = 0; tabx[i] != NULL; i++)
	{
		if (my_strcmp(tabx[i], "exit\n") == 0)
			exit(0);
		if (my_strcmp(tabx[i], "cd\n") == 0)
			use_cd(tabx, envi);
		if (my_strcmp(tabx[i], "setenv\n") == 0)
		{
			int arg = 0;
			
			while (tabx[arg] != NULL)
				arg++;
			if (arg == 3)
				envi = use_setenv(tabx, envi);
			else
				my_putstr("Wrong argument\n");
			return (envi);
		}	
		if (my_strcmp(tabx[i], "unsetenv\n") == 0)
		{	
			int i;
			int check = 0;
			
			for (i = 0; tabx[i] != NULL; i++)
				check++;
			if( check < 2)
			{
				my_putstr("unsetenv:Too few arguments\n");
			}
			else
			{	
				envi = use_unsetenv(tabx, envi);
				return (envi);
			}	
		}	
		if (my_strcmp(tabx[i], "env\n") == 0)
			use_env(envi);
	}
	return(envi);
}

void	use_cd(char **tabx, char **envi)
{
	int	i = 0;
	int	j;
	int	len;
	char    *home = NULL;

	while (tabx[i] != NULL)
        	i++;
	if (i == 1)
	{
		for (i = 0; envi[i] != NULL; i++)
		{
			if (my_strcmp("HOME=", envi[i]) == 0)  
			{
				for (j = 5; envi[i][j] != '\0'; j++)
				{
					len++;
				}	
				home = malloc(sizeof(char) * len);
			        for (j = 0, len = 5; envi[i][j] != '\0'; j++, len++)
				{
					home[j] = envi[i][len];
				}
			}
		}
		chdir(home);
	}	
	if (i == 2)
		chdir(tabx[1]);
}

char  **use_setenv(char **tabx, char **envi)
{
	int i = 0;
        int j = 0;
        int lines = 0;
        int columns = 0;
        char **env_cpy = NULL;
	char *new_var;
	
	while (envi[i] != NULL)
	{
		i++;
	}
	lines = i;
	i = 0;
	env_cpy = malloc(sizeof(char *) * (lines + 2));
	while (envi[i] != NULL)
	{
		columns = my_strlen(envi[i]);
		env_cpy[i] = malloc(sizeof(char) * columns);
		while (envi[i][j] != '\0')
		{
			env_cpy[i][j] = envi[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	new_var = my_str_concatenate_equal(tabx[1], tabx[2]);
	j = my_strlen(new_var);
	env_cpy[i] = malloc(sizeof(char) * j);
	env_cpy[i] = new_var;
	env_cpy[i+1] = NULL;
	return (env_cpy);
}

char	**use_unsetenv(char **tabx, char **envi)
{
	int	i = 0;
	int	j = 1;
	int	double_check = 0;
	int	i_cpy = 0;
	int	new_lines = 2;
	char	**env_cpy;

	
	while (envi[i] != NULL && tabx[j] != NULL )
	{
		if(my_strcmp(tabx[j], envi[i]) == 0)
		{	
			double_check++;
			j++;
		}
		i++;
	}
	i = 0;
	j = 1;
	if (double_check == 0)
	{
		my_putstr("Variable doesn't exist\n");
		env_cpy = my_tabcpy(envi);
	}	
	else
	{
		while (envi[i] != NULL && tabx[j] != NULL)
		{
			if(my_strcmp(tabx[j], envi[i]) == 0)
			{
				j++;
			}
			new_lines++;
			i++;
		}
		i = 0;
		j = 1;
		env_cpy = malloc(sizeof(char*) * new_lines + 1);
		while (envi[i] != NULL && tabx[j] != NULL)
		{
			env_cpy[i_cpy] = my_strdup(envi[i]);
			i_cpy++;
			i++;
			if(my_strcmp(tabx[j], envi[i]) == 0)
			{
				j++;
			}
		}
		env_cpy[i+1] = NULL;
	}
	return(env_cpy);
}	
	
void	use_env(char **envi)
{
	my_print_tab(envi);
}
