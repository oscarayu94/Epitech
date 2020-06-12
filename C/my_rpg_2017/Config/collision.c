/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	get_white_pixels(sfImage *collide, sfVector2f mov, sfRectangleShape *mc)
{
	unsigned int	x;
	unsigned int	y;

	x = (unsigned int)sfRectangleShape_getPosition(mc).x;
	y = (unsigned int)sfRectangleShape_getPosition(mc).y;
	if (sfImage_getPixel(collide, x, y).r == 255 ||
	    sfImage_getPixel(collide, (x + 16), (y + 25)).r == 255)
		return (0);
	return (1);
}
