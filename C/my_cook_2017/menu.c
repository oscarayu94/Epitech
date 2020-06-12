/*
** EPITECH PROJECT, 2018
** Cooking
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"


button_t	*buttonInitialise(assets_t assets)
{
	button_t	*button;
	sfRectangleShape	*rect;

	button = malloc(sizeof(*button));
	rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(rect, assets.pos);
	sfRectangleShape_setSize(rect, assets.size);
	sfRectangleShape_setFillColor(rect, assets.color);
	button->rect = rect;
	return (button);
}

button_t	*set_button(assets_t assets, float_t draw, sfColor color)
{
	button_t	*button;

	assets.color = color;
	assets.pos.x = draw.posx;
	assets.pos.y = draw.posy;
	assets.size.x = draw.sizex;
	assets.size.y = draw.sizey;
	button = buttonInitialise(assets);
	return (button);
}

int	buttonIsClicked(button_t *button, sfVector2i clickPos, assets_t assets, render_t rndr)
{
	sfVector2f	pos;
	sfVector2f	size;

	clickPos = sfMouse_getPosition(rndr.screen);
	pos = sfRectangleShape_getPosition(button->rect);
	size = sfRectangleShape_getSize(button->rect);
	if ((clickPos.x < pos.x + size.x && clickPos.x > pos.x) &&
	    (clickPos.y < pos.y + size.y && clickPos.y > pos.y))
		return (1);
	else
		return (0);
}
