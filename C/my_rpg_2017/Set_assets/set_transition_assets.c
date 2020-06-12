/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

transition_t	set_transition(transition_t trans)
{
	trans.tran = draw_transition();
	trans.clock.clock = sfClock_create();
	trans.battle = draw_battle_begins();
	trans.mov.x = -5;
	trans.mov.y = 0;
	trans.counter = 0;
	trans.scroll = 0;
	return (trans);
}
