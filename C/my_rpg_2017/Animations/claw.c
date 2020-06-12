/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	claw_one(combat_t combat)
{
	if (combat.animate.frame5.left > 672) {
		combat.animate.frame5.left = 0;
		if (combat.shield == 1)
			combat.rowena.hp = combat.rowena.hp - (20 * 50 / 100);
		else
			combat.rowena.hp = combat.rowena.hp - 20;
		combat.turn = 0;
		combat.shield = 0;
	}
	return (combat);
}

combat_t	claw_anim(combat_t combat)
{
	if (combat.turn == -4)
		if (combat.anim.sec >= 0.10) {
			combat.animate.frame5.left = combat.animate.
				frame5.left + 164;
			combat = claw_one(combat);
			sfRectangleShape_setTextureRect(combat.atk2_anim,
							combat.animate.frame5);
			sfClock_restart(combat.anim.clock);
		}
	return (combat);
}
