/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_run(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {100, mode.height - 150};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/run.png",
							     NULL), sfTrue);
	return (atk);
}

sfRectangleShape	*draw_hp(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	pos = {mode.width - 650, mode.height - 600};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setFillColor(atk, sfRed);
	return (atk);
}

sfRectangleShape	*draw_fiend_hp(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	pos = {180 / 2, mode.height - 600};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setFillColor(atk, sfBlue);
	return (atk);
}

sfRectangleShape	*draw_mp(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {350, 10};
	sfVector2f	pos = {mode.width - 575, mode.height - 565};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setFillColor(atk, sfYellow);
	return (atk);
}

text_t	draw_name(sfVideoMode mode)
{
	text_t	name;
	sfVector2f	pos = {mode.width - 800, mode.height - 600};

	name.font = sfFont_createFromFile("Fonts/title.otf");
	name.text = sfText_create();
	sfText_setString(name.text, "Rowena");
	sfText_setFont(name.text, name.font);
	sfText_setCharacterSize(name.text, 40);
	sfText_setColor(name.text, sfWhite);
	sfText_setPosition(name.text, pos);
	return (name);
}
