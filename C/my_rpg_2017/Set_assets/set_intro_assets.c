/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

intro_t	set_intro(intro_t intro, sfVideoMode mode, char *str)
{
	intro.intro = draw_intro();
	intro.skip = draw_skip(mode);
	intro.clock.clock = sfClock_create();
	intro.bg = draw_background();
	intro.plume = draw_plume();
	intro.mov.i = -2;
	intro.mov.speed = 0;
	intro.mov.enter = 0;
	intro.end = 0;
	intro.text_pos.x = 15;
	intro.ptr = malloc(sizeof(char*) * my_strlen(str));
	sfText_setPosition(intro.intro.text, intro.text_pos);
	return (intro);
}
