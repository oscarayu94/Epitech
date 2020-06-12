/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	destroy_intro(intro_t intro)
{
	sfSprite_destroy(intro.bg);
	sfRectangleShape_destroy(intro.plume);
	sfText_destroy(intro.intro.text);
	sfFont_destroy(intro.intro.font);
	sfText_destroy(intro.skip.text);
	sfFont_destroy(intro.skip.font);
	sfClock_destroy(intro.clock.clock);
}
