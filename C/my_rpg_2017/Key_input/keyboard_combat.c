/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** By Joan Barrera Casanovas
*/

#include "../list.h"

sfRectangleShape	*invi_combat(sfVideoMode mode)
{
	sfRectangleShape	*invc;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {100, mode.height - 450};

	invc = sfRectangleShape_create();
	sfRectangleShape_setPosition(invc, pos);
	sfRectangleShape_setSize(invc, size);
	sfRectangleShape_setFillColor(invc, sfTransparent);
	if (pos.x != 1) {
		sfRectangleShape_setOutlineThickness(invc, 10);
		sfRectangleShape_setOutlineColor(invc, sfWhite);
	}
	else
		sfRectangleShape_setOutlineThickness(invc, 0);
	return (invc);
}

sfRectangleShape	*escape_back(sfRectangleShape *invc)
{
	sfVector2f	mov = {100, 630};

	sfRectangleShape_setPosition(invc, mov);
	return (invc);
}

all_t	*combat_horizontal(sfRectangleShape *invc, render_t rndr, all_t *all, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {-900, 0};
	sfVector2f	org2 = {900, 0};

	if (sfKeyboard_isKeyPressed(sfKeyRight) && all->combat.turn == 2) {
		mov.x =+ 300;
		sfRectangleShape_move(invc, mov);
		if (sfRectangleShape_getPosition(invc).x >= 1000)
			sfRectangleShape_move(invc, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft) && all->combat.turn == 2) {
		mov.x =- 300;
		sfRectangleShape_move(invc, mov);
		if (sfRectangleShape_getPosition(invc).x <= 0)
			sfRectangleShape_move(invc, org2);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight) && all->combat.turn == 3) {
		mov.x =+ 300;
		sfRectangleShape_move(invc, mov);
		if (sfRectangleShape_getPosition(invc).x >= 1000)
			sfRectangleShape_move(invc, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft) && all->combat.turn == 3) {
		mov.x =- 300;
		sfRectangleShape_move(invc, mov);
		if (sfRectangleShape_getPosition(invc).x <= 0)
			sfRectangleShape_move(invc, org2);
	}
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		invc = escape_back(invc);
	return (all);
}

all_t	*move_key_combat(sfRectangleShape *invc, render_t rndr, all_t *all, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {0, 400};
	sfVector2f	org2 =  {0, -400};

	if (sfKeyboard_isKeyPressed(sfKeyUp) && all->combat.turn == 0) {
		mov.y =- 100;
		sfRectangleShape_move(invc, mov);
		if (sfRectangleShape_getPosition(invc).y <= 590)
			sfRectangleShape_move(invc, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) && all->combat.turn == 0) {
		mov.y =+ 100;
		sfRectangleShape_move(invc, mov);
		if (sfRectangleShape_getPosition(invc).y >= 990)
			sfRectangleShape_move(invc, org2);
	}
	combat_input(invc, rndr, all, all->a);
	combat_horizontal(invc, rndr, all, all->a);
	return (all);
}
