/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	combat_bars(combat_t combat)
{
	combat.bar.hp_bar.x = 250 * combat.rowena.hp / 100;
	combat.bar.enemy_bar.x = 250 * combat.enemy_hp / 100;
	combat.bar.hp_bar.y = 25;
	combat.bar.enemy_bar.y = 25;
	combat.bar.mp_bar.x = 175 * combat.rowena.mp / 100;
	combat.bar.mp_bar.y = 10;
	sfRectangleShape_setSize(combat.hp, combat.bar.hp_bar);
	sfRectangleShape_setSize(combat.mp, combat.bar.mp_bar);
	sfRectangleShape_setSize(combat.hp_bar, combat.bar.enemy_bar);
	return (combat);
}
