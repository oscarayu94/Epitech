/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_lreturn(sfVideoMode mode)
{
	sfRectangleShape	*lreturn;
	sfVector2f	size = {550, 100};
	sfVector2f	pos;

	pos.x = mode.width / 2 - (size.x / 2);
	pos.y = mode.height / 2 + 275;
	lreturn = sfRectangleShape_create();
	sfRectangleShape_setPosition(lreturn, pos);
	sfRectangleShape_setSize(lreturn, size);
	sfRectangleShape_setTexture(lreturn,
				    sfTexture_createFromFile("Img/return.png",
							     NULL), sfTrue);
	return (lreturn);
}

text_t	draw_loadtitle(sfVideoMode mode)
{
	text_t	title;
	sfVector2f	pos = {mode.width / 2 - 260, mode.height / 2 - 350};
	sfColor	color;

	color = sfColor_fromRGBA(150, 0, 24, 255);
	title.font = sfFont_createFromFile("Fonts/title.otf");
	title.text = sfText_create();
	sfText_setString(title.text, "~Load Game~");
	sfText_setFont(title.text, title.font);
	sfText_setCharacterSize(title.text, 125);
	sfText_setColor(title.text, color);
	sfText_setPosition(title.text, pos);
	return (title);
}
