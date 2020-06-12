/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	frame_one(combat_t combat)
{
	if (combat.animate.frame4.left == 154 &&
	    combat.animate.frame4.top == 0) {
		combat.animate.frame4.left = 173;
		combat.animate.frame4.width = 82;
	}
	if (combat.animate.frame4.left == 250 &&
	    combat.animate.frame4.top == 0) {
		combat.animate.frame4.left = 275;
		combat.animate.frame4.width = 74;
	}
	if (combat.animate.frame4.left == 352 &&
	    combat.animate.frame4.top == 0) {
		combat.animate.frame4.left = 365;
		combat.animate.frame4.width = 70;
	}
	return (combat);
}

combat_t	frame_two(combat_t combat)
{
	if (combat.animate.frame4.left > 365 &&
	    combat.animate.frame4.top == 0) {
		combat.animate.frame4.top = 68;
		combat.animate.frame4.left = 0;
	}
	if (combat.animate.frame4.left == 0 &&
	    combat.animate.frame4.top == 68) {
		combat.animate.frame4.width = 73;
	}
	if (combat.animate.frame4.left == 154 &&
	    combat.animate.frame4.top == 68) {
		combat.animate.frame4.left = 173;
		combat.animate.frame4.width = 82;
	}
	return (combat);
}

combat_t	frame_three(combat_t combat)
{
	if (combat.animate.frame4.left == 250 &&
	    combat.animate.frame4.top == 68) {
		combat.animate.frame4.left = 275;
		combat.animate.frame4.width = 74;
	}
	if (combat.animate.frame4.left == 352 &&
	    combat.animate.frame4.top == 68) {
		combat.animate.frame4.left = 365;
		combat.animate.frame4.width = 70;
	}
	if (combat.animate.frame4.left > 365 &&
	    combat.animate.frame4.top == 68) {
		combat.animate.frame4.top = 136;
		combat.animate.frame4.left = 0;
	}
	return (combat);
}

combat_t	frame_four(combat_t combat)
{
	if (combat.animate.frame4.left == 154 &&
	    combat.animate.frame4.top == 136)
		combat.animate.frame4.left = 173;
	if (combat.animate.frame4.left > 154 &&
	    combat.animate.frame4.top == 136) {
		if (rand() % 100 <= 50) {
			combat.turn = -8;
			return (combat);
		}
		combat.animate.frame4.left = 0;
		combat.animate.frame4.top = 0;
		combat.turn = 1;
	}
	return (combat);
}

combat_t	run_anim(combat_t combat)
{
	if (combat.turn == -7)
		if (combat.anim.sec >= 0.05) {
			combat.animate.frame4.left = combat.animate.
				frame4.left + 77;
			combat = frame_one(combat);
			combat = frame_two(combat);
			combat = frame_three(combat);
			combat = frame_four(combat);
			sfRectangleShape_setTextureRect(combat.dust,
							combat.animate.frame4);
			sfClock_restart(combat.anim.clock);
		}
	return (combat);
}
