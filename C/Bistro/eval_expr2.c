/*
** EPITECH PROJECT, 2017
** Bistro-matic
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#define SIZE (4096)

char sign_representation(int i)
{
	if (i == 0)
		return('(');
	if (i == 1)
		return(')');
	if (i == 2)
		return('+');
	if (i == 3)
		return('-');
	if (i == 4)
		return('*');
	if (i == 5)
		return('/');
	if (i == 6)
		return('%');
	return('c');
}

int sign_transform(char **str, char *av)
{
	int	i;
        int	g;
	int	mem;
	char	*ptr; 

	i = 0;
	g = 0;
	ptr = (*str);
	while (av[i] != '\0')
        {
	        mem = g;
        	if (ptr[g] == '\0')
        		return(0);
                if (av[i] == ptr[g])
                        (*str)[g] = sign_representation(i);
                if (mem != g)
			i = 0;
		if (i == 6 && ptr[g] != '\0')
                {
                        g++;
                        i = 0;
                }
		else 
			i++;
        }
        return(0);
}

int number_transform(char **str, char *av)
{
	int	i;
	int	g;
	int	mem;
	char	*ptr;

	i = 0;
	g = 0;
	ptr = (*str);
	while (av[i] != '\0')
	{
		mem = g;
		if (av[i] == ptr[g])
		{
		        (*str)[g] = i + '0';
			g++;
		}
		if (mem != g)
			i = 0;
		if(i == 9 && ptr[g] != '\0')
		{
			g++;
			i = 0;
		}
		if (ptr[g] == '\0')
			return(0);
		i++;
	}
	return(0);
}

int parenth(char *str)
{
	int	g;
	int	h;
	int	i;
	char	*ptr;

	g = 0;
	h = 0;
	i = 0;
	ptr = str;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '(')
			g++;
		if (ptr[i] == ')')
			h++;
		i++;
	}
	i = i-1;
        if (ptr[i] == '+' || ptr[i] == '-' ||			\
	   ptr[i] == '*' || ptr[i] == '/' || ptr[i] == '%')
		return(0);
	if (h == g)
		return(1);
	else
		return(0);
}

void space_find(char **a)
{
	char	*str;
	int	i;

	str = (*a);
	i = 0;
        while (str[i] != '\0')
	{
	        if (str[i] == ' ')
		{
			while (str[i] != '\0')
			{
				str[i] = str[i+1];
				i++;
			}
			i = 0;
		}
		i++;
	}
        (*a) = str;
}


