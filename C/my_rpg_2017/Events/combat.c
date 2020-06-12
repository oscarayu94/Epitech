/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	outline_combat(combat_t combat, sfVector2i click)
{
	outline_rect(combat.atk, click, sfWhite);
	outline_rect(combat.skl, click, sfWhite);
	outline_rect(combat.skl1, click, sfWhite);
	outline_rect(combat.skl2, click, sfWhite);
	outline_rect(combat.item, click, sfWhite);
	outline_rect(combat.mint, click, sfWhite);
	outline_rect(combat.pineapple, click, sfWhite);
	outline_rect(combat.run, click, sfWhite);
}

void	color_animations(combat_t combat)
{
	sfRectangleShape_setFillColor(combat.skl_anim, sfBlue);
	sfRectangleShape_setFillColor(combat.skl2_anim,
				      sfColor_fromRGB(255, 215, 0));
	sfRectangleShape_setFillColor(combat.atk_anim, sfRed);
	sfRectangleShape_setFillColor(combat.mana, sfBlue);
}

combat_t	combat_mode(combat_t combat, sfVector2i click)
{
	combat.clock = clock_config(combat.clock);
	combat.anim = clock_config(combat.anim);
	combat = combat_bars(combat);
	combat = draco_anim(combat);
	combat = combat_animations(combat);
	combat = combat_scenarios(combat, click);
	if (combat.rowena.hp > 230)
		combat.rowena.hp = 230;
	if (combat.rowena.mp > 250)
		combat.rowena.mp = 250;
	return (combat);
}

all_t	*combat_event(render_t rndr, all_t *all, sfVector2i click, int a)
{
	analyse_combat(rndr, all, all->a);
	render_combat(rndr, all->combat);
	outline_combat(all->combat, click);
	color_animations(all->combat);
	if (all->combat.rowena.hp <= 0 && all->combat.turn == 0)
		all->a = 6;
	if (all->combat.enemy_hp <= 0 && all->combat.turn == 0)
		all->a = 2;
	return (all);
}
