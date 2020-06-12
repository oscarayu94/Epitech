/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_load(render_t rndr, load_t load)
{
	sfRenderWindow_drawRectangleShape(rndr.window, load.empty, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, load.table, NULL);
	sfRenderWindow_drawText(rndr.window, load.text.text, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, load.save1, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, load.save2, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, load.save3, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, load.lreturn, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, load.invi, NULL);
}
