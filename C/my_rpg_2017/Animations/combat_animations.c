/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	combat_animations(combat_t combat)
{
	combat = slash_anim(combat);
	combat = azure_slash_anim(combat);
	combat = shield_anim(combat);
	combat = potion_anim(combat);
	combat = mana_anim(combat);
	combat = run_anim(combat);
	combat = claw_anim(combat);
	return (combat);
}
