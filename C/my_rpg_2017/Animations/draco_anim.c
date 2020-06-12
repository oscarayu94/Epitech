/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	draco_one(combat_t combat)
{
	if (combat.draco_frame.left == 91) {
		combat.draco_frame.top = 0;
		combat.draco_frame.left = 88;
		combat.draco_frame.width = 100;
		combat.draco_frame.height = 100;
	}
	if (combat.draco_frame.left == 176) {
		combat.draco_frame.top = 0;
		combat.draco_frame.left = 197;
		combat.draco_frame.width = 79;
		combat.draco_frame.height = 100;
	}
	return (combat);
}

combat_t	draco_two(combat_t combat)
{
	if (combat.draco_frame.left == 285) {
		combat.draco_frame.top = 0;
		combat.draco_frame.left = 276;
		combat.draco_frame.width = 75;
		combat.draco_frame.height = 100;
	}
	if (combat.draco_frame.left > 285)
		combat.draco_frame.left = 3;
	if (combat.draco_frame.left == 3) {
		combat.draco_frame.top = 0;
		combat.draco_frame.left = 3;
		combat.draco_frame.width = 87;
		combat.draco_frame.height = 100;
	}
	return (combat);
}

combat_t	draco_anim(combat_t combat)
{
	if (combat.clock.sec >= 0.15) {
		combat.draco_frame.left = combat.draco_frame.left + 88;
		combat = draco_one(combat);
		combat = draco_two(combat);
		sfRectangleShape_setTextureRect(combat.enemy,
						combat.draco_frame);
		sfClock_restart(combat.clock.clock);
	}
	return (combat);
}
