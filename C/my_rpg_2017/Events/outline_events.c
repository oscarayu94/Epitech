/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	outline_rect(sfRectangleShape *button, sfVector2i click, sfColor color)
{
	if (mouse_rect(button, click) == 1) {
		sfRectangleShape_setOutlineThickness(button, 10);
		sfRectangleShape_setOutlineColor(button, color);
	}
	else
		sfRectangleShape_setOutlineThickness(button, 0);
}
