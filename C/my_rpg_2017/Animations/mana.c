/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	mana_one(combat_t combat)
{
	if (combat.animate.frame3.left > 768 &&
	    combat.animate.frame3.top == 0) {
		combat.animate.frame3.left = 0;
		combat.animate.frame3.top = 192;
	}
	if (combat.animate.frame3.left > 768 &&
	    combat.animate.frame3.top == 192) {
		combat.animate.frame3.left = 0;
		combat.animate.frame3.top = 384;
	}
	return (combat);
}

combat_t	mana_two(combat_t combat)
{
	if (combat.animate.frame3.left > 768 &&
	    combat.animate.frame3.top == 384) {
		combat.animate.frame3.left = 0;
		combat.animate.frame3.top = 576;
	}
	if (combat.animate.frame3.left > 768 &&
	    combat.animate.frame3.top == 576) {
		combat.animate.frame3.left = 0;
		combat.animate.frame3.top = 768;
	}
	if (combat.animate.frame3.left > 768 &&
	    combat.animate.frame3.top == 768) {
		combat.animate.frame3.left = 0;
		combat.animate.frame3.top = 0;
		combat.rowena.mp += 50;
		combat.item2--;
		combat.turn = 1;
	}
	return (combat);
}

combat_t	mana_anim(combat_t combat)
{
	if (combat.turn == -6)
		if (combat.anim.sec >= 0.05) {
			combat.animate.frame3.left = combat.animate.
				frame3.left + 192;
			combat = mana_one(combat);
			combat = mana_two(combat);
			sfRectangleShape_setTextureRect(combat.mana,
							combat.animate.frame3);
			sfClock_restart(combat.anim.clock);
		}
	return (combat);
}
