/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_table(sfVideoMode mode)
{
	sfRectangleShape	*load;
	sfVector2f	size = {mode.width / 2 - 100, mode.height / 2 + 250};
	sfVector2f	pos;
	sfColor	color;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 - 350;
	color = sfColor_fromRGBA(25, 25, 112, 75);
	load = sfRectangleShape_create();
	sfRectangleShape_setPosition(load, pos);
	sfRectangleShape_setSize(load, size);
	sfRectangleShape_setFillColor(load, color);
	sfRectangleShape_setOutlineThickness(load, 10);
	sfRectangleShape_setOutlineColor(load, sfWhite);
	return (load);
}

sfRectangleShape	*draw_emptiness(sfVideoMode mode)
{
	sfRectangleShape	*empty;
	sfVector2f	size = {mode.width, mode.height};
	sfVector2f	pos;
	sfColor	color;

	color = sfColor_fromRGBA(0, 0, 0, 50);
	empty = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty, pos);
	sfRectangleShape_setSize(empty, size);
	sfRectangleShape_setFillColor(empty, color);
	return (empty);
}

sfRectangleShape	*draw_save_one(sfVideoMode mode)
{
	sfRectangleShape	*save1;
	sfVector2f	size = {550, 100};
	sfVector2f	pos;
	sfColor	color;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 - 175;
	color = sfColor_fromRGBA(153, 224, 230, 150);
	save1 = sfRectangleShape_create();
	sfRectangleShape_setPosition(save1, pos);
	sfRectangleShape_setSize(save1, size);
	sfRectangleShape_setFillColor(save1, color);
	return (save1);
}

sfRectangleShape	*draw_save_two(sfVideoMode mode)
{
	sfRectangleShape	*save2;
	sfVector2f	size = {550, 100};
	sfVector2f	pos;
	sfColor	color;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 - 25;
	color = sfColor_fromRGBA(153, 224, 230, 150);
	save2 = sfRectangleShape_create();
	sfRectangleShape_setPosition(save2, pos);
	sfRectangleShape_setSize(save2, size);
	sfRectangleShape_setFillColor(save2, color);
	return (save2);
}

sfRectangleShape	*draw_save_three(sfVideoMode mode)
{
	sfRectangleShape	*save3;
	sfVector2f	size = {550, 100};
	sfVector2f	pos;
	sfColor	color;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 + 125;
	color = sfColor_fromRGBA(153, 224, 230, 150);
	save3 = sfRectangleShape_create();
	sfRectangleShape_setPosition(save3, pos);
	sfRectangleShape_setSize(save3, size);
	sfRectangleShape_setFillColor(save3, color);
	return (save3);
}
