/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	analyse_escape(render_t rndr, escape_t esc, int a)
{
	sfRenderWindow_setKeyRepeatEnabled(rndr.window, sfFalse);
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		a = escape_return(a);
		a = move_key_pause(esc.invi, rndr, esc, a);
		close_window(rndr);
	}
	return (a);
}

all_t	*analyse_combat(render_t rndr, all_t *all, int a)
{
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		all->a = return_game(all->a);
		move_key_combat(all->combat.invc, rndr, all, all->a);
//		all->a = move_key_combat(all->combat.invc,
//					 rndr, all->combat, all->a);
		close_window(rndr);
	}
	return (all);
}

int	analyse_gameover(render_t rndr, int a)
{
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		close_window(rndr);
	}
	return (a);
}

int	analyse_slots(render_t rndr, pause_t pause, int a)
{
	sfRenderWindow_setKeyRepeatEnabled(rndr.window, sfFalse);
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		a = return_menu(a);
		a = move_key_slots(pause.sloti, rndr, pause, a);
		close_window(rndr);
	}
	return (a);
}

int	analyse_intro(render_t rndr, int a, scroll_t scroll)
{
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		close_window(rndr);
	}
	return (a);
}

int	analyse_equip(render_t rndr, pause_t pause, int a)
{
	sfRenderWindow_setKeyRepeatEnabled(rndr.window, sfFalse);
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		a = return_menu(a);
		a = move_key_back(pause.bpai, rndr, pause, a);
		close_window(rndr);
	}
	return (a);
}

int     analyse_status(render_t rndr, pause_t pause, int a)
{
        while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
                a = return_menu(a);
                a = move_key_status(pause.istat, rndr, pause, a);
                close_window(rndr);
        }
        return (a);
}

int     analyse_stree(render_t rndr, pause_t pause, int a)
{
        while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
                a = return_menu(a);
                close_window(rndr);
        }
        return (a);
}
