/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_pause(render_t rndr, pause_t pause)
{
	sfRenderWindow_drawRectangleShape(rndr.window, pause.pause, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.invi, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.skills, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.party, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.save, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.loadrect, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.hud, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.inv, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.preturn, NULL);
}
