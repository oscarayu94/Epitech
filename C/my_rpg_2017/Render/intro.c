/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_intro(render_t rndr, intro_t intro)
{
	sfRenderWindow_clear(rndr.window, sfBlack);
	sfRenderWindow_drawSprite(rndr.window, intro.bg, NULL);
	sfRenderWindow_drawText(rndr.window, intro.skip.text, NULL);
	sfRenderWindow_drawText(rndr.window, intro.intro.text, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, intro.plume, NULL);
}
