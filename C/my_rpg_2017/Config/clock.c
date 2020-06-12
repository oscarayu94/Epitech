/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

count_t	clock_config(count_t clock)
{
	clock.time = sfClock_getElapsedTime(clock.clock);
	clock.sec = clock.time.microseconds / 1000000.0;
	return (clock);
}
