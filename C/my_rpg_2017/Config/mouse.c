/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfVector2i	mouse_detection(render_t rndr, sfVector2i click)
{
	click = sfMouse_getPosition(NULL);
	sfRenderWindow_display(rndr.window);
	return (click);
}
