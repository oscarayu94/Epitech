/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

render_t	create_window(render_t rndr, char *str)
{
	rndr.window = sfRenderWindow_create(rndr.mode, str, sfFullscreen, NULL);
	sfRenderWindow_setVerticalSyncEnabled(rndr.window, sfTrue);
	sfRenderWindow_setFramerateLimit(rndr.window, 80);
	return (rndr);
}
