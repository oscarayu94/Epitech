/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*rect_texture(sfRectangleShape *rect, char *str)
{
	sfTexture	*texture;

	texture = sfTexture_createFromFile(str, NULL);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	return (rect);
}
