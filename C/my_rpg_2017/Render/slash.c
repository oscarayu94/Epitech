/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	my_put_slash(framebuffer_t *element, int pos, int alpha, int color)
{
	element->pixels[pos] = 6;
	element->pixels[pos + 1] = 10;
	element->pixels[pos + 2] = 147;
	element->pixels[pos + 3] = alpha;
}

void	prototype_moon(int y, int x, render_t *rndr,
		       sfVector2i center, framebuffer_t *element)
{
	int	pos;

	pos = ((y * element->width) + x) * 4;
	if (((x - center.x) * (x - center.x))
	    + ((y - center.y)
	       * (y - center.y)) <= 1500)
		if (((x - center.x - 20) * (x - center.x - 20))
		    + ((y - center.y  + 00) * (y - center.y + 00)) > 900)
			my_put_slash(element, pos,
				     rndr->alpha, rndr->alpha);
}

sfVector2i	move_moon(sfVector2i center, render_t *rndr)
{
	if (center.x > 0)
		center.x = center.x - 100;
	return (center);
}

void	print_moon(render_t *rndr, framebuffer_t *element, int *s_snow)
{
	draw_black(element, rndr, rndr->center2);
	draw_moon(element, rndr, rndr->center2, s_snow);
	rndr->center2 = move_moon(rndr->center2, rndr);
	if (rndr->center2.x <= 0) {
		rndr->num = -84;
		draw_black(element, rndr, rndr->center2);
	}
}

void	render_slash(render_t *rndr, framebuffer_t *element2, int *s_slash)
{
	if (rndr->num != -84)
		print_moon(rndr, element2, s_slash);
	sfTexture_updateFromPixels(rndr->texture2,
				   element2->pixels,
				   rndr->mode.width,
				   rndr->mode.height, 0, 0);
	sfSprite_setTexture(rndr->sprite2, rndr->texture2, sfTrue);
	sfRenderWindow_drawSprite(rndr->window, rndr->sprite2, NULL);
}
