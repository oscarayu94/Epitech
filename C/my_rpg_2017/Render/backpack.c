/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_backpack(render_t rndr, pause_t pause)
{
	sfRenderWindow_drawRectangleShape(rndr.window, pause.pause, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.helm, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.eqin, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.chest, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.legs, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.arms, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.weapon, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.bpa, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.bpai, NULL);
	sfRenderWindow_drawText(rndr.window, pause.text2.text, NULL);
}
