/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	title_input(sfRectangleShape *invi, render_t rndr, title_t title, int a)
{
	if (detect_rect(invi, title.load) == 1)
		if(sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 1;
	if (detect_rect(invi, title.start) == 1)
		if(sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 10;
	if (detect_rect(invi, title.exit) == 1)
		if(sfKeyboard_isKeyPressed(sfKeyReturn))
			sfRenderWindow_close(rndr.window);
	return (a);
}

int	pause_input(sfRectangleShape *invi, render_t rndr, escape_t esc, int a)
{
	if (detect_rect(invi, esc.back) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 0;
	if (detect_rect(invi, esc.exit) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			sfRenderWindow_close(rndr.window);
	return (a);
}

int	slots_input(sfRectangleShape *invi, render_t rndr, pause_t pause, int a)
{
	if (detect_rect(invi, pause.invi) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 7;
	if (detect_rect(invi, pause.skills) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 8;
	if (detect_rect(invi, pause.party) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 9;
	if (detect_rect(invi, pause.save) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 11;
	if (detect_rect(invi, pause.loadrect) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 11;
	if (detect_rect(invi, pause.preturn) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 11;
	return (a);
}

all_t	*combat_input(sfRectangleShape *invi, render_t rndr, all_t *all, int a)
{
	if (detect_rect(invi, all->combat.atk) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			all->combat.turn = -1;
	if (detect_rect(invi, all->combat.skl) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			all->combat.turn = 2;
	if (detect_rect(invi, all->combat.skl1) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
//			invi = escape_back(invi);
			all->combat.turn = -3;
		}
	if (detect_rect(invi, all->combat.skl2) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
			all->combat.turn = -2;
		}
	if (detect_rect(invi, all->combat.item) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			all->combat.turn = 3;
	if (detect_rect(invi, all->combat.pineapple) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
			all->combat.turn = -5;
		}
	if (detect_rect(invi, all->combat.mint) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
			all->combat.turn = -6;
		}
	if (detect_rect(invi, all->combat.run) == 1)
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
			all->combat.turn = -7;
		}
	return (all);
}
