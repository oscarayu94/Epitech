/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

text_t	draw_over(sfVideoMode mode)
{
	text_t	name;
	sfVector2f	pos = {220, 100};

	name.font = sfFont_createFromFile("Fonts/title.otf");
	name.text = sfText_create();
	sfText_setString(name.text, "\t\tGAME OVER\nYour journey ends here...");
	sfText_setFont(name.text, name.font);
	sfText_setCharacterSize(name.text, 160);
	sfText_setColor(name.text, sfColor_fromRGB(128, 0, 24));
	sfText_setPosition(name.text, pos);
	return (name);
}

sfRectangleShape	*draw_retry(sfVideoMode mode)
{
	sfRectangleShape	*retry;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2;
	retry = sfRectangleShape_create();
	sfRectangleShape_setPosition(retry, pos);
	sfRectangleShape_setSize(retry, size);
	sfRectangleShape_setFillColor(retry, sfGreen);
	return (retry);
}

sfRectangleShape	*draw_game_exit(sfVideoMode mode)
{
	sfRectangleShape	*exit;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height - (mode.height / 3);
	exit = sfRectangleShape_create();
	sfRectangleShape_setPosition(exit, pos);
	sfRectangleShape_setSize(exit, size);
	sfRectangleShape_setFillColor(exit, sfRed);
	return (exit);
}
