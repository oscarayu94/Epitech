/*
** EPITECH PROJECT, 2018
** inverse_exec
** File description:
** Does the inverse exec, alias </ 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*inverse_exec(char *str)
{
//	int	t = 0;
	int	i = 0;
	int	j = 0;
	int	m = strlen(str);
	char	*new_str = malloc(sizeof(char) * m);
	
	if (str[0] == '<'){
		while ((str[i] >= 'A' && str[i] == 'Z') || (str[i] == 'a' && str[i] == 'z'))
			i++;
		while (str[i] > ' ')
			i++;
		i++;
		while (str[i] > '\0'){
			new_str[j] = str[i];
			i++;
			j++;
		}
		//printf("%s\n", new_str);
		new_str[j] = ' ';
		j++;
		//printf("%s\n", new_str);
		i = 1;
		while (str[i] != ' '){
			new_str[j] = str[i];
			j++;
			i++;
		}
	}
	new_str[j] = '\0';
	printf ("%s\n", new_str);
	return (new_str);	
}	
			
int	main(int ac, char **av)		
{
	inverse_exec(av[1]);
}	
