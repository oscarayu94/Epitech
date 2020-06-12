/*
** EPITECH PROJECT, 2018
** rb_putsr
** File description:
** put str rebirthed
*/

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str)
{
	int	j;

	j = 0;
	while ( str[j] != '\0')
	{
		j++;
	}	
	return (j);	
}

void	my_onscreen(int i, char *str)
{
	write (i, str, my_strlen(str));
}

void	rb_putstr(char *str)
{
	int	i;
	char	*err_str;

        err_str = "Error, string pointer is null.\n";
	i = 0;
	
	if (str == NULL)
	{
		i = 2;
		my_onscreen(i, err_str);
		exit (84);
	}	
	else
	{
		i = 1;
		my_onscreen(i, str);
	}	
		
        
}

