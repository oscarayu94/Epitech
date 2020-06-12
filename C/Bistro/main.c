/*
** EPITECH PROJECT, 2017
** main
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#define SIZE (4096)

int main(int ac, char **av)
{
	char    buff[1];
	int     size;
        char    str[100];
	int     j;
	int     c;
        char    *a;

	size = read(0, buff, 1);
	j = 0;
	while (size > 0)
        {
         	str[j] = buff[0];
		j++;
		size = read(0, buff, 1);
	}
        str[j - 1] = '\0';
        a = str;
        c = parenth(a);
	if (c == 0)
	{
                write(1, "syntax error\n", 14);
	        return(0);
	}
        space_find(&a);
	number_transform(&a, av[1]);
	sign_transform(&a, av[2]);
	operator2(&a);
	return(0);
}
