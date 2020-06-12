/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** By Joan Barrera Casanovas
*/

#include "../list.h"

int	detect_rect(sfRectangleShape *rect, sfRectangleShape *rect2)
{
	sfVector2f	trans;
	sfVector2f	recti;

	trans = sfRectangleShape_getPosition(rect);
	recti = sfRectangleShape_getPosition(rect2);
	if (trans.x == recti.x && trans.y == recti.y)
		return (1);
	return (0);
}
