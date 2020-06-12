/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	maintenance_event(int a, render_t rndr, pause_t pause, sfVector2i click)
{
	a = analyse_stree(rndr, pause, a);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.pause, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, pause.maintenance, NULL);
	return (a);
}
