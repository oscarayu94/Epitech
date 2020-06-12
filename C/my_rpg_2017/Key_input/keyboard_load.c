/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** By Joan Barrera Casanovas
*/

#include "../list.h"

sfRectangleShape	*invi_load(sfVideoMode mode)
{
	sfRectangleShape	*inv;
	sfVector2f	size = {550, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 - 175;
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

int	move_key_load(sfRectangleShape *invi, render_t rndr, load_t load, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {0, 600};
	sfVector2f	org2 =  {0, -600};

	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		mov.y =- 150;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y == 215)
			sfRectangleShape_move(invi, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		mov.y =+ 150;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y > 815)
			sfRectangleShape_move(invi, org2);
	}
	a = load_input(invi, rndr, load, a);
	return (a);
}
