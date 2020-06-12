/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

text_t	draw_intro(void)
{
	text_t	text;

	text.text = sfText_create();
	text.font = sfFont_createFromFile("Fonts/title.otf");
	sfText_setFont(text.text, text.font);
	sfText_setCharacterSize(text.text, 80);
	sfText_setColor(text.text, sfBlack);
	return (text);
}

text_t	draw_skip(sfVideoMode mode)
{
	text_t	text;
	sfVector2f	pos = {mode.width - 400, mode.height - 150};

	text.text = sfText_create();
	text.font = sfFont_createFromFile("Fonts/title.otf");
	sfText_setFont(text.text, text.font);
	sfText_setCharacterSize(text.text, 45);
	sfText_setStyle(text.text, sfTextBold);
	sfText_setColor(text.text, sfWhite);
	sfText_setString(text.text, "Hold Right Control \nto Skip or Continue");
	sfText_setPosition(text.text, pos);
	return (text);
}

sfSprite	*draw_background(void)
{
	sfSprite	*bg;
	sfTexture	*texture;

	texture = sfTexture_createFromFile("Img/pach.png", NULL);
	bg = sfSprite_create();
	sfSprite_setTexture(bg, texture, sfTrue);
	return (bg);
}

sfRectangleShape	*draw_plume(void)
{
	sfRectangleShape	*plume;
	sfVector2f	size = {103, 135};

	plume = sfRectangleShape_create();
	sfRectangleShape_setSize(plume, size);
	plume = rect_texture(plume, "Img/plume.png");
	return (plume);
}
