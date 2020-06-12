/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	outline_gameover(gameover_t over, sfVector2i click)
{
	outline_rect(over.retry, click, sfWhite);
	outline_rect(over.exit, click, sfWhite);
}

int	gameover_event(int a, render_t rndr, gameover_t over, sfVector2i click)
{
	a = analyse_gameover(rndr, a);
	outline_gameover(over, click);
	exit_button(over.exit, click, rndr);
	a = game_button(over.retry, click, rndr, a);
	render_gameover(rndr, over);
	return (a);
}


