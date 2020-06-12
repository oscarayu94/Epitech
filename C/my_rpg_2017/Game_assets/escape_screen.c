/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_esc_emptiness(sfVideoMode mode)
{
	sfRectangleShape	*empty;
	sfVector2f	size = {mode.width, mode.height};
	sfVector2f	pos;
	sfColor	color;

	color = sfColor_fromRGBA(255, 255, 255, 5);
	empty = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty, pos);
	sfRectangleShape_setSize(empty, size);
	sfRectangleShape_setFillColor(empty, color);
	return (empty);
}

sfRectangleShape	*draw_esc_return(sfVideoMode mode)
{
	sfRectangleShape	*ereturn;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;
	sfColor	color;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2;
	color = sfColor_fromRGBA(153, 224, 230, 150);
	ereturn = sfRectangleShape_create();
	sfRectangleShape_setPosition(ereturn, pos);
	sfRectangleShape_setSize(ereturn, size);
	sfRectangleShape_setFillColor(ereturn, color);
	return (ereturn);
}

sfRectangleShape	*draw_esc_exit(sfVideoMode mode)
{
	sfRectangleShape	*exit;
	sfVector2f	size = {350, 100};
	sfVector2f	pos;
	sfColor	color;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height - (mode.height / 3);
	color = sfColor_fromRGBA(255, 0, 0, 150);
	exit = sfRectangleShape_create();
	sfRectangleShape_setPosition(exit, pos);
	sfRectangleShape_setSize(exit, size);
	sfRectangleShape_setFillColor(exit, color);
	return (exit);
}

text_t	draw_escape_title(sfVideoMode mode)
{
	text_t	title;
	sfVector2f	pos = {mode.width / 2 - 300, mode.height / 2 - 200};
	sfColor	color;

	color = sfColor_fromRGBA(150, 0, 24, 255);
	title.font = sfFont_createFromFile("Fonts/title.otf");
	title.text = sfText_create();
	sfText_setString(title.text, "~Paused Game~");
	sfText_setFont(title.text, title.font);
	sfText_setCharacterSize(title.text, 125);
	sfText_setColor(title.text, color);
	sfText_setPosition(title.text, pos);
	return (title);
}
