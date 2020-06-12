/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void    draw_moon(framebuffer_t *element, render_t *rndr,
		  sfVector2i center, int *s_snow)
{
	int	x;

	for (int y = 0; y != rndr->mode.height; y++)
		for (x = 0; x != rndr->mode.width; x++)
			prototype_moon(y, x, rndr, center, element);
}

void	draw_snow(framebuffer_t *element, render_t *rndr,
		  sfVector2i center, int *s_snow)
{
	int	x;

	for (int y = 0; y != rndr->mode.height; y++)
		for (x = 0; x != rndr->mode.width; x++)
			prototype_one(y, x, rndr, center, element);
}

void	draw_black(framebuffer_t *element, render_t *rndr, sfVector2i center)
{
	int	pos;

	for (int y = 0; y != rndr->mode.height; y++)
		for (int x = 0; x != rndr->mode.width; x++) {
			pos = ((y * element->width) + x) * 4;
			my_put_pixel(element, pos, 0, 255);
		}
}
