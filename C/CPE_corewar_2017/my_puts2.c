/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "list.h"

void	my_putchar_error(char c)
{
        write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
        int     i = 0;
	
        while(str[i] != '\0') {
                my_putchar_error(str[i]);
                i = i + 1;
        }
        return (0);
}

int my_strcmp(char *pwd, char *line)
{
        int     i;

        for (i = 0; pwd[i] != '\0'; i++)
        {
                if(pwd[i] != line[i])
                        return (0);
        }
        if (line[i] == pwd[i])
                return (1);
        return (0);
}
