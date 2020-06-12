/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	my_put_pixel(framebuffer_t *element, int pos, int alpha, int color)
{
	element->pixels[pos] = 255;
	element->pixels[pos + 1] = 255;
	element->pixels[pos + 2] = 255;
	element->pixels[pos + 3] = alpha;
}

void	prototype_one(int y, int x, render_t *rndr,
		      sfVector2i center, framebuffer_t *element)
{
	int	num = x;
	int	pos;

	for (pos = ((y * element->width) + x) * 4;
	     x < num + 100 && x < rndr->mode.width;
	     x = x + 100) {
		if (((x - center.x) * (x - center.x))
		    + ((y - center.y)
		       * (y - center.y)) <= 100)
			if (((x - center.x - 20) * (x - center.x))
			    + ((y - center.y) * (y - center.y)) < 300)
				my_put_pixel(element, pos,
					     rndr->alpha, rndr->alpha);
		}
}

sfVector2i	position(sfVector2i center, render_t *rndr, int nb, int nb2)
{
	if (center.y < rndr->mode.height)
		center.y = center.y + nb;
	else
		center.y = 0;
	if (center.x < rndr->mode.width)
		center.x = center.x + nb2;
	else
		center.x = 0;
	return (center);
}

void	print_balls(render_t *rndr, framebuffer_t *element, int *s_snow)
{
	sfVector2i	center;

	center.x = rndr->center.x - 10;
	center.y = rndr->center.y - 25;
	draw_black(element, rndr, center);
	draw_snow(element, rndr, rndr->center, s_snow);
	rndr->center = position(rndr->center, rndr, 25, 10);
	draw_snow(element, rndr, rndr->faster, s_snow);
	rndr->faster = position(rndr->faster, rndr, 30, 15);
	draw_snow(element, rndr, rndr->more_faster, s_snow);
	rndr->more_faster = position(rndr->more_faster, rndr, 45, 30);
}

void	render_snow(render_t *rndr, framebuffer_t *element, int *s_snow)
{
	sfRenderWindow_clear(rndr->window, sfBlack);
	print_balls(rndr, element, s_snow);
	sfTexture_updateFromPixels(rndr->texture, element->pixels,
				   rndr->mode.width,
				   rndr->mode.height, 0, 0);
	sfSprite_setTexture(rndr->sprite, rndr->texture, sfTrue);
	sfRenderWindow_drawSprite(rndr->window, rndr->sprite, NULL);
}
