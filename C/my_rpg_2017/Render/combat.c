/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	render_animations(render_t rndr, combat_t combat)
{
	if (combat.turn == -1)
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.atk_anim, NULL);
	if (combat.turn == -2)
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.skl_anim, NULL);
	if (combat.turn == -3)
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.skl2_anim, NULL);
	if (combat.turn == -4)
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.atk2_anim, NULL);
	if (combat.turn == -5)
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.potion, NULL);
	if (combat.turn == -6)
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.mana, NULL);
}

void	render_interface(render_t rndr, combat_t combat)
{
	sfRenderWindow_drawRectangleShape(rndr.window, combat.atk, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, combat.skl, NULL);
	if (combat.turn == 2) {
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.skl1, NULL);
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.skl2, NULL);
	}
	sfRenderWindow_drawRectangleShape(rndr.window,
					  combat.item, NULL);
	if (combat.turn == 3) {
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.pineapple, NULL);
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.mint, NULL);
	}
	sfRenderWindow_drawRectangleShape(rndr.window, combat.run, NULL);
}

void	render_enemy(render_t rndr, combat_t combat)
{
	if (combat.enemy_hp > 0) {
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.enemy, NULL);
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.hp_bar, NULL);
	}
}

void	render_player(render_t rndr, combat_t combat)
{
	sfRenderWindow_drawRectangleShape(rndr.window,
					  combat.mc, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window,
					  combat.hp, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window,
					  combat.mp, NULL);
	sfRenderWindow_drawText(rndr.window,
				combat.name.text, NULL);
}

void	render_combat(render_t rndr, combat_t combat)
{
	sfRenderWindow_setView(rndr.window, combat.view);
	sfRenderWindow_clear(rndr.window, sfBlack);
	render_enemy(rndr, combat);
	render_interface(rndr, combat);
	render_player(rndr, combat);
	sfRenderWindow_drawText(rndr.window, combat.turn_name.text, NULL);
	render_animations(rndr, combat);
	if (combat.turn == -7)
		sfRenderWindow_drawRectangleShape(rndr.window,
						  combat.dust, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, combat.invc, NULL);
}
