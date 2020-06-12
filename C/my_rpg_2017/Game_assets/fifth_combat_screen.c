/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

text_t	draw_turn(sfVideoMode mode)
{
	text_t	name;
	sfVector2f	pos = {mode.width / 2 - 40 * 2, 100};

	name.font = sfFont_createFromFile("Fonts/title.otf");
	name.text = sfText_create();
	sfText_setFont(name.text, name.font);
	sfText_setCharacterSize(name.text, 40);
	sfText_setColor(name.text, sfWhite);
	sfText_setPosition(name.text, pos);
	return (name);
}


sfRectangleShape	*draw_maintenance(void)
{
	sfRectangleShape       *rect;
	sfVector2f	size = {453, 55};
	sfVector2f	pos = {950, 450};

	rect = sfRectangleShape_create();
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setPosition(rect, pos);
	rect = rect_texture(rect, "Img/under_maintenance.png");
	return(rect);
}
