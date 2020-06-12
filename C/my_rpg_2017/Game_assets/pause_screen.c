/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_pause(sfVideoMode mode)
{
	sfRectangleShape	*pause;
	sfVector2f	size = {mode.width, mode.height};
	sfVector2f	pos = {0, 0};

	pause = sfRectangleShape_create();
	sfRectangleShape_setPosition(pause, pos);
	sfRectangleShape_setSize(pause, size);
	pause = rect_texture(pause, "Img/background.png");
	return (pause);
}

sfRectangleShape	*draw_header(sfVideoMode mode)
{
	sfRectangleShape	*header;
	sfVector2f	size = {640, mode.height};
	sfVector2f	pos = {0, 0};

	header = sfRectangleShape_create();
	sfRectangleShape_setPosition(header, pos);
	sfRectangleShape_setSize(header, size);
	sfRectangleShape_setFillColor(header, sfBlack);
	return (header);
}

sfRectangleShape	*draw_invi(sfVideoMode mode)
{
	sfRectangleShape	*invi;
	sfVector2f	size = {300, 100};
	sfVector2f	pos;

	pos.x = 640 / 4;
	pos.y = 40;
	invi = sfRectangleShape_create();
	sfRectangleShape_setPosition(invi, pos);
	sfRectangleShape_setSize(invi, size);
	invi = rect_texture(invi, "Img/items2.png");
	return (invi);
}

sfRectangleShape	*draw_skills(sfVideoMode mode)
{
	sfRectangleShape	*skills;
	sfVector2f	size = {300, 100};
	sfVector2f	pos;

	pos.x = 640 / 4;
	pos.y = 220;
	skills = sfRectangleShape_create();
	sfRectangleShape_setPosition(skills, pos);
	sfRectangleShape_setSize(skills, size);
	skills = rect_texture(skills, "Img/equip.png");
	return (skills);
}

sfRectangleShape	*draw_party(sfVideoMode mode)
{
	sfRectangleShape	*party;
	sfVector2f	size = {300, 100};
	sfVector2f	pos;

	pos.x = 640 / 4;
	pos.y = 400;
	party = sfRectangleShape_create();
	sfRectangleShape_setPosition(party, pos);
	sfRectangleShape_setSize(party, size);
	party = rect_texture(party, "Img/status.png");
	return (party);
}

sfRectangleShape	*draw_save(sfVideoMode mode)
{
	sfRectangleShape	*save;
	sfVector2f	size = {300, 100};
	sfVector2f	pos;

	pos.x = 640 / 4;
	pos.y = 580;
	save = sfRectangleShape_create();
	sfRectangleShape_setPosition(save, pos);
	sfRectangleShape_setSize(save, size);
	save = rect_texture(save, "Img/tree.png");
	return (save);
}

sfRectangleShape	*draw_loadrect(sfVideoMode mode)
{
	sfRectangleShape	*load;
	sfVector2f	size = {300, 100};
	sfVector2f	pos;

	pos.x = 640 / 4;
	pos.y = 760;
	load = sfRectangleShape_create();
	sfRectangleShape_setPosition(load, pos);
	sfRectangleShape_setSize(load, size);
	load = rect_texture(load, "Img/save.png");
	return (load);
}

sfRectangleShape	*draw_preturn(sfVideoMode mode)
{
	sfRectangleShape	*preturn;
	sfVector2f	size = {300, 100};
	sfVector2f	pos;

	pos.x = 640 / 4;
	pos.y = 940;
	preturn = sfRectangleShape_create();
	sfRectangleShape_setPosition(preturn, pos);
	sfRectangleShape_setSize(preturn, size);
	preturn = rect_texture(preturn, "Img/load2.png");
	return (preturn);
}

sfRectangleShape	*draw_hud(sfVideoMode mode)
{
	sfRectangleShape	*hud;
	sfVector2f	size = {700, 400};
	sfVector2f	pos;

	pos.x = 1920 / 2;
	pos.y = 680;
	hud = sfRectangleShape_create();
	sfRectangleShape_setPosition(hud, pos);
	sfRectangleShape_setSize(hud, size);
	hud = rect_texture(hud, "Img/hud.png");
	return (hud);
}
