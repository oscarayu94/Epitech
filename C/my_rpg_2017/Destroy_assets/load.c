/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	destroy_load(load_t load)
{
	sfRectangleShape_destroy(load.empty);
	sfRectangleShape_destroy(load.table);
	sfRectangleShape_destroy(load.save1);
	sfRectangleShape_destroy(load.save2);
	sfRectangleShape_destroy(load.save3);
	sfRectangleShape_destroy(load.lreturn);
	sfRectangleShape_destroy(load.invi);
	sfText_destroy(load.text.text);
	sfFont_destroy(load.text.font);
	sfClock_destroy(load.clock.clock);
}
