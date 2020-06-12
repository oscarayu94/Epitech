/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	plume_anim(intro_t intro)
{
	intro.plume_pos.x = sfText_findCharacterPos(intro.intro.text,
						    intro.mov.i).x;
	intro.plume_pos.y = sfText_findCharacterPos(intro.intro.text,
						    intro.mov.i).y -
		sfText_getCharacterSize(intro.intro.text) / 1.5;
	sfRectangleShape_setPosition(intro.plume, intro.plume_pos);
}

intro_t	text_anim(intro_t intro, render_t rndr, char *str)
{
	if (intro.mov.speed == 1 && intro.mov.enter == 0)
		intro.mov = text_speed(intro, rndr.mode, str, 0.000001);
	if (intro.mov.enter == 0)
		intro.mov = text_speed(intro, rndr.mode, str, 0.15);
	return (intro);
}
