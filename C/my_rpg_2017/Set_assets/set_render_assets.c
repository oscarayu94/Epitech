/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

render_t	*set_render(render_t *rndr)
{
	rndr->mode = sfVideoMode_getDesktopMode();
	rndr->alpha = 255;
	rndr->center.y = 300;
	rndr->center2.y = 300;
	rndr->faster.x = 10;
	rndr->faster.y = 0;
	rndr->texture = sfTexture_create(rndr->mode.width, rndr->mode.height);
	rndr->texture2 = sfTexture_create(rndr->mode.width, rndr->mode.height);
	rndr->sprite = sfSprite_create();
	rndr->sprite2 = sfSprite_create();
	rndr->center.x = rndr->mode.width - 20;
	rndr->center2.x = rndr->mode.width - 20;
	rndr->mode.bitsPerPixel = 8;
	return (rndr);
}
