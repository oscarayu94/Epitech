/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	mouse_rect(sfRectangleShape *rect, sfVector2i click)
{
	sfVector2f	pos;
	sfVector2f	size;

	pos = sfRectangleShape_getPosition(rect);
	size = sfRectangleShape_getSize(rect);
	if (click.x < pos.x + size.x && click.x > pos.x &&
	    click.y < pos.y + size.y && click.y > pos.y)
		return (1);
	return (0);
}
