/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	outline_escape(escape_t esc, sfVector2i click)
{
	outline_rect(esc.back, click, sfWhite);
	outline_rect(esc.exit, click, sfWhite);
}

int	escape_event(int a, render_t rndr, escape_t esc, sfVector2i click)
{
	a = analyse_escape(rndr, esc, a);
	render_escape(rndr, esc);
	outline_escape(esc, click);
	sfRenderWindow_setView(rndr.window, esc.view);
	exit_button(esc.exit, click, rndr);
	a = title_button(esc.back, click, rndr, a);
	return (a);
}
