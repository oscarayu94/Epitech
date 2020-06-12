/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	close_window(render_t rndr)
{
	if (rndr.event.type == sfEvtClosed)
		sfRenderWindow_close(rndr.window);
}

int	analyse_menu(render_t rndr, title_t title, int a)
{
	sfRenderWindow_setKeyRepeatEnabled(rndr.window, sfFalse);
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		a = move_key(title.invi, rndr, title, a);
		close_window(rndr);
	}
	return (a);
}

int	analyse_ingame(render_t rndr, int a)
{
	sfRenderWindow_setKeyRepeatEnabled(rndr.window, sfTrue);
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		a = pause_key(a);
		a = escape_game(a);
		close_window(rndr);
	}
	return (a);
}

int	analyse_load(render_t rndr, load_t load, int a)
{
	sfRenderWindow_setKeyRepeatEnabled(rndr.window, sfFalse);
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		a = move_key_load(load.invi, rndr, load, a);
		close_window(rndr);
	}
	return (a);
}

int	analyse_pause(render_t rndr, pause_t pause, int a)
{
	sfRenderWindow_setKeyRepeatEnabled(rndr.window, sfFalse);
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		a = return_game(a);
		a = move_pause_key(pause.inv, rndr, pause, a);
		close_window(rndr);
	}
	return (a);
}
