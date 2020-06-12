/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_load(sfVideoMode mode)
{
	sfRectangleShape	*load;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2;
	load = sfRectangleShape_create();
	sfRectangleShape_setPosition(load, pos);
	sfRectangleShape_setSize(load, size);
	load = rect_texture(load, "Img/load.png");
	return (load);
}

sfRectangleShape	*draw_start(sfVideoMode mode)
{
	sfRectangleShape	*start;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 + 150;
	start = sfRectangleShape_create();
	sfRectangleShape_setPosition(start, pos);
	sfRectangleShape_setSize(start, size);
	start = rect_texture(start, "Img/start.png");
	return (start);
}

sfRectangleShape	*draw_exit(sfVideoMode mode)
{
	sfRectangleShape	*exit;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 + 300;
	exit = sfRectangleShape_create();
	sfRectangleShape_setPosition(exit, pos);
	sfRectangleShape_setSize(exit, size);
	exit = rect_texture(exit, "Img/exit.png");
	return (exit);
}

sfRectangleShape	*draw_gametitle(sfVideoMode mode)
{
	sfRectangleShape	*title;
	sfVector2f	size = {1299, 425};
	sfVector2f	pos;

	pos.x = mode.width / 2 - 575;
	pos.y = mode.height / 2 - 450;
	title = sfRectangleShape_create();
	sfRectangleShape_setPosition(title, pos);
	sfRectangleShape_setSize(title, size);
	title = rect_texture(title, "Img/title.png");
	return (title);
}
