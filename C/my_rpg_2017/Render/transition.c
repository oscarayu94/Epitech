/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_transition(render_t rndr, transition_t trans)
{
	sfRenderWindow_drawRectangleShape(rndr.window, trans.tran, NULL);
	sfRenderWindow_drawText(rndr.window, trans.battle.text, NULL);
}
