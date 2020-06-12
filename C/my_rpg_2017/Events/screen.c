/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	screen_event(int a, render_t rndr, title_t title, sfVector2i click)
{
	a = analyse_menu(rndr, title, a);
	render_screen(rndr, title);
	outline_screen(title, click);
	exit_button(title.exit, click, rndr);
	a = start_button(title.start, click, rndr, a);
	a = load_button(title.load, click, rndr, a);
	return (a);
}

void	outline_screen(title_t title, sfVector2i click)
{
	outline_rect(title.load, click, sfWhite);
	outline_rect(title.start, click, sfWhite);
	outline_rect(title.exit, click, sfWhite);
}
