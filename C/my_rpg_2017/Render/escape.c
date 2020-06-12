/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_escape(render_t rndr, escape_t esc)
{
	sfRenderWindow_clear(rndr.window, sfBlack);
	sfRenderWindow_drawRectangleShape(rndr.window, esc.empty, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, esc.back, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, esc.exit, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, esc.invi, NULL);	
	sfRenderWindow_drawText(rndr.window, esc.title.text, NULL);
}
