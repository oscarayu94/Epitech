/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	first_frame(combat_t combat)
{
	if (combat.animate.frame2.left > 764 &&
	    combat.animate.frame2.top == 0) {
		combat.animate.frame2.left = 0;
		combat.animate.frame2.top = 192;
	}
	if (combat.animate.frame2.left > 764 &&
	    combat.animate.frame2.top == 192) {
		combat.animate.frame2.left = 0;
		combat.animate.frame2.top = 384;
	}
	return (combat);
}

combat_t	second_frame(combat_t combat)
{
	if (combat.animate.frame2.left > 764 &&
	    combat.animate.frame2.top == 384) {
		combat.animate.frame2.left = 0;
		combat.animate.frame2.top = 576;
	}
	if (combat.animate.frame2.left > 764 &&
	    combat.animate.frame2.top == 576) {
		combat.animate.frame2.left = 0;
		combat.animate.frame2.top = 768;
	}
	return (combat);
}

combat_t	third_frame(combat_t combat)
{
	if (combat.animate.frame2.left > 764 &&
	    combat.animate.frame2.top == 768) {
		combat.animate.frame2.left = 0;
		combat.animate.frame2.top = 960;
	}
	if (combat.animate.frame2.left > 764 &&
	    combat.animate.frame2.top == 960) {
		combat.animate.frame2.left = 0;
		combat.animate.frame2.top = 0;
		combat.rowena.mp -= 25;
		combat.turn = 1;
		combat.shield = 1;
	}
	return (combat);
}

combat_t	shield_anim(combat_t combat)
{
	if (combat.turn == -3)
		if (combat.anim.sec >= 0.05) {
			combat.animate.frame2.left = combat.animate.
				frame2.left + 191;
			combat = first_frame(combat);
			combat = second_frame(combat);
			combat = third_frame(combat);
			sfRectangleShape_setTextureRect(combat.skl2_anim,
							combat.animate.frame2);
			sfClock_restart(combat.anim.clock);
		}
	return (combat);
}
