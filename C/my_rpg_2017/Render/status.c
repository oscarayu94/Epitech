/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_status(render_t rndr, pause_t pause)
{
	sfRenderWindow_drawRectangleShape(rndr.window, pause.stat, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.istat, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.heal, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.hnum, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.hnumf, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.empty, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.empty2, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.empty3, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.empty4, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.empty5, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.empty6, NULL);
}
