/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_items(render_t rndr, pause_t pause)
{
	sfRenderWindow_drawRectangleShape(rndr.window, pause.pause, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.slots, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.slot1, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.slot2, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.slot3, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.sloti, NULL);
	sfRenderWindow_drawText(rndr.window, pause.text.text, NULL);
}
