/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	slash_anim(combat_t combat)
{
	if (combat.turn == -1)
		if (combat.anim.sec >= 0.15) {
			combat.animate.frame.left = combat.animate.frame.left +
				136;
			if (combat.animate.frame.left > 408) {
				combat.animate.frame.left = 0;
				combat.enemy_hp = combat.enemy_hp -
					combat.rowena.atk;
				combat.turn = 1;
			}
			sfRectangleShape_setTextureRect(combat.atk_anim,
							combat.animate.frame);
			sfClock_restart(combat.anim.clock);
		}
	return (combat);
}

combat_t	azure_slash_anim(combat_t combat)
{
	if (combat.turn == -2)
		if (combat.anim.sec >= 0.15) {
			combat.animate.frame.left = combat.animate.frame.left +
				136;
			if (combat.animate.frame.left > 408) {
				combat.animate.frame.left = 0;
				combat.enemy_hp = combat.enemy_hp -
					(combat.rowena.atk + (combat.rowena.atk * 0.75));
				combat.rowena.mp -= 100;
				combat.turn = 1;
			}
			sfRectangleShape_setTextureRect(combat.skl_anim,
							combat.animate.frame);
			sfClock_restart(combat.anim.clock);
		}
	return (combat);
}

