/*
** EPITECH PROJECT, 2018
** second_status
** File description:
** 
*/

#include "../list.h"

sfRectangleShape	*draw_hnumberf(sfVideoMode mode)
{
	sfRectangleShape	*hnumf;
	sfVector2f	size = {65, 50};
	sfVector2f	pos = {1640, 180};

	hnumf = sfRectangleShape_create();
	sfRectangleShape_setPosition(hnumf, pos);
	sfRectangleShape_setSize(hnumf, size);
	sfRectangleShape_setTexture(hnumf, sfTexture_createFromFile("Img/status_bonus_null.png", NULL), sfTrue);
	return (hnumf);
}

sfRectangleShape	*draw_empty(sfVideoMode mode)
{
	sfRectangleShape	*empty;
	sfVector2f	size = {75, 50};
	sfVector2f	pos = {1410, 290};

	empty = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty, pos);
	sfRectangleShape_setSize(empty, size);
	sfRectangleShape_setTexture(empty, sfTexture_createFromFile("Img/focusp.png", NULL), sfTrue);
	return (empty);
}

sfRectangleShape	*draw_empty2(sfVideoMode mode)
{
	sfRectangleShape	*empty2;
	sfVector2f	size = {60, 40};
	sfVector2f	pos = {1420, 400};

	empty2 = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty2, pos);
	sfRectangleShape_setSize(empty2, size);
	sfRectangleShape_setTexture(empty2, sfTexture_createFromFile("Img/defense-base.png", NULL), sfTrue);
	return (empty2);
}

sfRectangleShape	*draw_empty3(sfVideoMode mode)
{
	sfRectangleShape	*empty3;
	sfVector2f	size = {65, 50};
	sfVector2f	pos = {1420, 490};

	empty3 = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty3, pos);
	sfRectangleShape_setSize(empty3, size);
	sfRectangleShape_setTexture(empty3, sfTexture_createFromFile("Img/status_current_defense.png", NULL), sfTrue);
	return (empty3);
}

sfRectangleShape	*draw_empty4(sfVideoMode mode)
{
	sfRectangleShape	*empty4;
	sfVector2f	size = {65, 50};
	sfVector2f	pos = {1640, 290};

	empty4 = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty4, pos);
	sfRectangleShape_setSize(empty4, size);
	sfRectangleShape_setTexture(empty4, sfTexture_createFromFile("Img/status_bonus_null.png", NULL), sfTrue);
	return (empty4);
}
