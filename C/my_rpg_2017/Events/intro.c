/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

intro_t	intro_interaction(intro_t intro)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace))
		intro.mov.speed = 1;
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && intro.mov.enter == 1) {
		intro.ptr[intro.mov.i] = intro.ptr[intro.mov.i + 1];
		intro.mov.speed = 0;
		intro.mov.enter = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue)
		intro.end++;
	if (sfKeyboard_isKeyPressed(sfKeyRControl) == sfFalse)
		intro.end = 0;
	return (intro);
}

scroll_t	text_move(intro_t intro, sfVideoMode mode, char *str)
{
	intro.ptr[intro.mov.i] = str[intro.mov.i];
	sfText_setString(intro.intro.text, intro.ptr);
	if (intro.mov.i <= my_strlen(str))
		intro.mov.i++;
	if (str[intro.mov.i] == '\n' && str[intro.mov.i + 1] == '\n')
		intro.mov.enter = 1;
	if (sfText_findCharacterPos(intro.intro.text, intro.mov.i).y >
	    mode.height - sfText_getCharacterSize(intro.intro.text) * 2) {
		intro.text_pos.y = sfText_getPosition(intro.intro.text).y;
		intro.text_pos.x = sfText_getPosition(intro.intro.text).x;
		intro.text_pos.y = intro.text_pos.y - mode.height / 2;
		sfText_setPosition(intro.intro.text, intro.text_pos);
	}
	intro.ptr[intro.mov.i + 1] = '\0';
	sfClock_restart(intro.clock.clock);
	return (intro.mov);
}

scroll_t	text_speed(intro_t intro, sfVideoMode mode, char *str, float nb)
{
	if (intro.clock.sec >= nb)
		intro.mov = text_move(intro, mode, str);
	return (intro.mov);
}

intro_t	intro_section(intro_t intro, render_t rndr, char *str)
{
	plume_anim(intro);
	intro.clock = clock_config(intro.clock);
	intro = intro_interaction(intro);
	intro = text_anim(intro, rndr, str);
	return (intro);
}

int	intro_event(int a, render_t rndr, intro_t intro, char *str)
{
	a = analyse_intro(rndr, a, intro.mov);
	if (intro.end >= 140)
		a = 2;
	render_intro(rndr, intro);
	return (a);
}
