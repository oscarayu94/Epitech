/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

framebuffer_t	*framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t	*element;

	element = malloc(sizeof(*element));
	element->width = width;
	element->height = height;
	return (element);
}
