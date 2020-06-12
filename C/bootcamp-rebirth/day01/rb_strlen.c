/*
** EPITECH PROJECT, 2018
** rb_strlen
** File description:
** strlen rebirth
*/

#include <stdio.h>
#include "list.h"

int	rb_strlen(char *str)
{
	int	i;

	char *c;

	c = "rb_strlen: String pointer is NULL";
		
	if (str == NULL)
	{
		rb_xerror(c);
	}	
	for (i = 0; str[i] != '\0'; i++)
		return (i);
}

