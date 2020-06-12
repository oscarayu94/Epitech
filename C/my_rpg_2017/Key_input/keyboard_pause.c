/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** By Joan Barrera Casanovas
*/

#include "../list.h"

sfRectangleShape	*invi_pause(sfVideoMode mode)
{
	sfRectangleShape	*inv;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;
	sfColor	color;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2;
	color = sfColor_fromRGBA(0, 0, 0, 0);
	inv = sfRectangleShape_create();
	sfRectangleShape_setPosition(inv, pos);
	sfRectangleShape_setSize(inv, size);
	sfRectangleShape_setFillColor(inv, color);
	if (pos.x != 1) {
		sfRectangleShape_setOutlineThickness(inv, 10);
		sfRectangleShape_setOutlineColor(inv, sfWhite);
	}
	else
		sfRectangleShape_setOutlineThickness(inv, 0);
	return (inv);
}

int	move_key_pause(sfRectangleShape *invi, render_t rndr, escape_t esc, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {0, 360};
	sfVector2f	org2 =  {0, -360};

	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		mov.y =- 180;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y == 360)
			sfRectangleShape_move(invi, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		mov.y =+ 180;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y == 900)
			sfRectangleShape_move(invi, org2);
	}
	a = pause_input(invi, rndr, esc, a);
	return (a);
}
