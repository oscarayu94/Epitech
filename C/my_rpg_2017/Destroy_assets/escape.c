/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	destroy_escape(escape_t esc)
{
	sfRectangleShape_destroy(esc.back);
	sfRectangleShape_destroy(esc.exit);
	sfRectangleShape_destroy(esc.empty);
	sfText_destroy(esc.title.text);
	sfFont_destroy(esc.title.font);
}
