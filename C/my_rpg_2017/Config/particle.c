/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	*start_snow(render_t *rndr)
{
	int	*b;

	b = malloc(sizeof(int) * 5);
	if (b == NULL)
		exit (84);
	for (int i = 0; i != 4; i++)
		b[i] = rand() % rndr->mode.width;
	b[4] = -84;
	return (b);
}

