/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** my_swap rebirth
*/

//echange valeurs

#include <stdio.h>

void	my_swap(int *a ,int *b)
{
	int	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
