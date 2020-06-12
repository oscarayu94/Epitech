/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_inv(sfVideoMode mode)
{
	sfRectangleShape	*inv;
	sfVector2f	size = {300, 100};
	sfVector2f	pos;
	sfColor	color;

	pos.x = 640 / 4;
	pos.y = 40;
	color = sfColor_fromRGBA(0, 0, 0, 0);
	inv = sfRectangleShape_create();
	sfRectangleShape_setPosition(inv, pos);
	sfRectangleShape_setSize(inv, size);
	sfRectangleShape_setFillColor(inv, color);
	if (pos.x != 1) {
		sfRectangleShape_setOutlineThickness(inv, 10);
		sfRectangleShape_setOutlineColor(inv, sfWhite);
	}
	return (inv);
}

int	move_pause_key(sfRectangleShape *invi, render_t rndr, pause_t pause, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {0, 1080};
	sfVector2f	org2 = {0, -1080};

	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		mov.y =- 180;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y < 39)
			sfRectangleShape_move(invi, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		mov.y =+ 180;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y > 940)
			sfRectangleShape_move(invi, org2);
	}
	a = slots_input(invi, rndr, pause, a);
	return (a);
}
