/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

all_t	*game_event(all_t *all, render_t rndr, sfVector2i click)
{
	all->a = analyse_ingame(rndr, all->a);
	all->trans = transition_pos(all->trans, all->game);
	all->game = render_game(rndr, all->game);
	all->trans.counter = random_encounter(all->game, all->trans);
	if (all->trans.counter == 400)
		all->a = -2;
	all->combat.enemy_hp = 200;
	return (all);
}

all_t	*transition_event(all_t *all, render_t rndr, sfVector2i click)
{
	all->trans.clock = clock_config(all->trans.clock);
	if (all->trans.clock.sec >= 0.020) {
		sfRectangleShape_move(all->trans.tran, all->trans.mov);
		sfClock_restart(all->trans.clock.clock);
	}
	render_transition(rndr, all->trans);
	if (all->trans.mov.x)
		all->trans.scroll++;
	if (all->trans.scroll == 120) {
		all->a = 5;
		all->trans.counter = 0;
		all->trans.scroll = 0;
	}
	return (all);
}

transition_t	transition_pos(transition_t trans, game_t game)
{
	trans.pos.x = sfView_getCenter(game.view).x;
	trans.pos.y = sfView_getCenter(game.view).y -
		(sfView_getSize(game.view).y / 2 + 10);
	sfRectangleShape_setPosition(trans.tran, trans.pos);
	trans.battle_pos.x = sfView_getCenter(game.view).x - 52;
	trans.battle_pos.y = sfView_getCenter(game.view).y - 20;
	sfText_setPosition(trans.battle.text, trans.battle_pos);
	return (trans);
}

int	random_encounter(game_t game, transition_t trans)
{
	if (game.mov.y)
		trans.counter++;
	return (trans.counter);
}
