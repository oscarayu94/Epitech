/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	exit_button(sfRectangleShape *exit, sfVector2i click, render_t rndr)
{
	if (mouse_rect(exit, click) == 1)
		if (sfMouse_isButtonPressed(sfMouseLeft))
			sfRenderWindow_close(rndr.window);
}

int	return_button(sfRectangleShape *back, sfVector2i click,
		      render_t rndr, int a)
{
	if (mouse_rect(back, click) == 1)
		if (sfMouse_isButtonPressed(sfMouseLeft))
			a = -1;
	return (a);
}

int	load_button(sfRectangleShape *load, sfVector2i click,
		    render_t rndr, int a)
{
	if (mouse_rect(load, click) == 1)
		if (sfMouse_isButtonPressed(sfMouseLeft))
			a = 1;
	return (a);
}

int	start_button(sfRectangleShape *start, sfVector2i click,
		     render_t rndr, int a)
{
	if (mouse_rect(start, click) == 1)
		if (sfMouse_isButtonPressed(sfMouseLeft))
			a = 10;
	return (a);
}

int	title_button(sfRectangleShape *title, sfVector2i click,
		     render_t rndr, int a)
{
	if (mouse_rect(title, click) == 1)
		if (sfMouse_isButtonPressed(sfMouseLeft))
			a = 0;
	return (a);
}
