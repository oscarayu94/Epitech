/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** By Joan Barrera Casanovas
*/

#include "../list.h"

sfRectangleShape	*invi(sfVideoMode mode)
{
	sfRectangleShape	*inv;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2;
	inv = sfRectangleShape_create();
	sfRectangleShape_setPosition(inv, pos);
	sfRectangleShape_setSize(inv, size);
	sfRectangleShape_setFillColor(inv, sfTransparent);
	if (pos.x != 1) {
		sfRectangleShape_setOutlineThickness(inv, 10);
		sfRectangleShape_setOutlineColor(inv, sfWhite);
	}
	else
		sfRectangleShape_setOutlineThickness(inv, 0);
	return (inv);
}

int	move_key(sfRectangleShape *invi, render_t rndr, title_t title, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {0, 450};
	sfVector2f	org2 =  {0, -450};

	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		mov.y =- 150;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y == 390)
			sfRectangleShape_move(invi, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		mov.y =+ 150;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y >= 990)
			sfRectangleShape_move(invi, org2);
	}
	a = title_input(invi, rndr, title, a);
	return (a);
}
