/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** strlen rebirth
*/

#include <stdio.h>

int	my_strlen(char *c)
{
        int	i = 0;

	while (c[i] != '\0')
		i++;
	return (i);
}
