/*
** EPITECH PROJECT, 2018
** status
** File description:
** By Joan Barrera
*/

#include "../list.h"

sfRectangleShape	*draw_status(sfVideoMode mode)
{
	sfRectangleShape	*stat;
	sfVector2f	size = {1200, 660};
	sfVector2f	pos = {640, 30};

	stat = sfRectangleShape_create();
	sfRectangleShape_setPosition(stat, pos);
	sfRectangleShape_setSize(stat, size);
	sfRectangleShape_setTexture(stat, sfTexture_createFromFile("Img/square_status_vari.png", NULL), sfTrue);
	return (stat);
}

sfRectangleShape	*draw_istat(sfVideoMode mode)
{
	sfRectangleShape	*istat;
	sfVector2f	size = {640, 83};
	sfVector2f	pos = {690, 63};

	istat = sfRectangleShape_create();
	sfRectangleShape_setPosition(istat, pos);
	sfRectangleShape_setSize(istat, size);
	sfRectangleShape_setFillColor(istat, sfTransparent);
	if (pos.x != 1) {
		sfRectangleShape_setOutlineThickness(istat, 7);
		sfRectangleShape_setOutlineColor(istat, sfRed);
	}
	else
		sfRectangleShape_setOutlineThickness(istat, 0);
	return (istat);
}

 int	move_key_status(sfRectangleShape *invi, render_t rndr, pause_t pause, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {0, 510};
	sfVector2f	org2 =  {0, -510};

	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		mov.y =- 102;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y <= 10)
			sfRectangleShape_move(invi, org);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		mov.y =+ 102;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).y >= 510)
			sfRectangleShape_move(invi, org2);
	}
	return (a);
}

sfRectangleShape	*draw_healty(sfVideoMode mode)
{
	sfRectangleShape	*heal;
	sfVector2f	size = {200, 60};
	sfVector2f	pos = {960, 75};

	heal = sfRectangleShape_create();
	sfRectangleShape_setPosition(heal, pos);
	sfRectangleShape_setSize(heal, size);
	sfRectangleShape_setTexture(heal, sfTexture_createFromFile("Img/status_type.png", NULL), sfTrue);
	return (heal);
}

sfRectangleShape	*draw_hnumber(sfVideoMode mode)
{
	sfRectangleShape	*hnum;
	sfVector2f	size = {75, 50};
	sfVector2f	pos = {1410, 180};

	hnum = sfRectangleShape_create();
	sfRectangleShape_setPosition(hnum, pos);
	sfRectangleShape_setSize(hnum, size);
	sfRectangleShape_setTexture(hnum, sfTexture_createFromFile("Img/status_healthf.png", NULL), sfTrue);
	return (hnum);
}
