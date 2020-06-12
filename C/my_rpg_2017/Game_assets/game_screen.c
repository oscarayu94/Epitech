/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfSprite	*draw_bg(sfVideoMode mode)
{
	sfSprite	*bg;
	sfTexture	*texture;

	texture = sfTexture_createFromFile("Img/island_image_2.png", NULL);
	bg = sfSprite_create();
	sfSprite_setTexture(bg, texture, sfTrue);
	return (bg);
}

sfRectangleShape	*draw_mc(sfVideoMode mode)
{
	sfRectangleShape	*mc;
	sfVector2f	size = {17, 26};
	sfVector2f	pos;

	pos.x = 1300;
	pos.y = 1000;
	mc = sfRectangleShape_create();
	sfRectangleShape_setPosition(mc, pos);
	sfRectangleShape_setSize(mc, size);
	mc = rect_texture(mc, "Img/rowena.png");
	return (mc);
}
