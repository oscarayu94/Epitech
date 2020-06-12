/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	load_event(int a, render_t rndr, load_t load, sfVector2i click)
{
	a = analyse_load(rndr, load, a);
	render_load(rndr, load);
	outline_load(load, click);
	a = return_button(load.lreturn, click, rndr, a);
	sfRectangleShape_setPosition(load.table, load.set);
	return (a);
}

void	outline_load(load_t load, sfVector2i click)
{
	outline_rect(load.save1, click, sfWhite);
	outline_rect(load.save2, click, sfWhite);
	outline_rect(load.save3, click, sfWhite);
	outline_rect(load.lreturn, click, sfWhite);
}

int	load_anim_event(int a, render_t rndr, load_t load, count_t clock)
{
	sfRenderWindow_clear(rndr.window, sfBlack);
	sfRenderWindow_drawRectangleShape(rndr.window, load.table, NULL);
	a = load_anim(clock, load, a);
	return (a);
}
