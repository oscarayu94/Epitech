/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_gameover(render_t rndr, gameover_t over)
{
	sfRenderWindow_clear(rndr.window, sfBlack);
	sfRenderWindow_clear(rndr.window, sfBlack);
	sfRenderWindow_drawText(rndr.window, over.text.text, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, over.retry, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, over.exit, NULL);
}
