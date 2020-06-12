/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

all_t	*intro_scenario(all_t *all, render_t rndr, sfVector2i click, char *str)
{
	if (all->a == 1)
		all->a = load_event(all->a, rndr, all->load, click);
	if (all->a == -1)
		all->a = load_anim_event(all->a, rndr,
					 all->load, all->load.clock);
	if (all->a == 10) {
		all->a = intro_event(all->a, rndr, all->intro, str);
		all->intro = intro_section(all->intro, rndr, str);
	}
	return (all);
}

all_t	*game_scenario(all_t *all, render_t rndr, sfVector2i click)
{
	if (all->a == 2)
		game_event(all, rndr, click);
	if (all->a == -2)
		transition_event(all, rndr, click);
	return (all);
}

all_t	*combat_scenario(all_t *all, render_t rndr, sfVector2i click)
{
	if (all->a == 6)
		all->a = gameover_event(all->a, rndr, all->over, click);
	return (all);
}

all_t	*menu_scenario(all_t *all, render_t rndr, sfVector2i click)
{
	if (all->a == 3)
		all->a = pause_event(all->a, rndr, all->pause, click);
	if (all->a == 4)
		all->a = escape_event(all->a, rndr, all->esc, click);
	if (all->a == 7)
		all->a = items_event(all->a, rndr, all->pause, click);
	if (all->a == 8)
		all->a = backpack_event(all->a, rndr, all->pause, click);
	if (all->a == 9)
		all->a = status_event(all->a, rndr, all->pause, click);
	if (all->a == 11)
		all->a = maintenance_event(all->a, rndr, all->pause, click);
        return (all);
}
