/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	outline_pause(pause_t pause, sfVector2i click)
{
	outline_rect(pause.invi, click, sfWhite);
	outline_rect(pause.skills, click, sfWhite);
	outline_rect(pause.party, click, sfWhite);
	outline_rect(pause.save, click, sfWhite);
	outline_rect(pause.loadrect, click, sfWhite);
	outline_rect(pause.preturn, click, sfWhite);
}

int	pause_event(int a, render_t rndr, pause_t pause, sfVector2i click)
{
	a = analyse_pause(rndr, pause, a);
	sfRenderWindow_setView(rndr.window, pause.pview);
	outline_pause(pause, click);
	render_pause(rndr, pause);
	return (a);
}
