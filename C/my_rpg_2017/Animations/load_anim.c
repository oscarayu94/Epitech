/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	load_anim(count_t clock_anim, load_t load, int a)
{
	clock_anim.time = sfClock_getElapsedTime(clock_anim.clock);
	clock_anim.sec = clock_anim.time.microseconds / 1000000.0;
	if (clock_anim.sec >= 0.01) {
		sfRectangleShape_move(load.table, load.offmov);
		sfClock_restart(clock_anim.clock);
	}
	if (sfRectangleShape_getPosition(load.table).x < -860)
		a = 0;
	return (a);
}
