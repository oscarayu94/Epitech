/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	game_button(sfRectangleShape *button, sfVector2i click,
		    render_t rndr, int a)
{
	if (mouse_rect(button, click) == 1)
		if (sfMouse_isButtonPressed(sfMouseLeft))
			a = 0;
	return (a);
}
