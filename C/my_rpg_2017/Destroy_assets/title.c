/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	destroy_title(title_t title)
{
	sfRectangleShape_destroy(title.load);
	sfRectangleShape_destroy(title.start);
	sfRectangleShape_destroy(title.exit);
	sfRectangleShape_destroy(title.title);
	sfRectangleShape_destroy(title.invi);
}
