/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_screen(render_t rndr, title_t title)
{
//	sfRenderWindow_clear(rndr.window, sfBlack);
	sfRenderWindow_drawRectangleShape(rndr.window, title.load, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, title.start, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, title.exit, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, title.title, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, title.invi, NULL);
}
