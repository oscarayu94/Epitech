/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

all_t	*set_particles(all_t *all, render_t *rndr)
{
	all->element = framebuffer_create(rndr->mode.width, rndr->mode.height);
	all->element2 = framebuffer_create(rndr->mode.width, rndr->mode.height);
	all->element->pixels = malloc(rndr->mode.width * rndr->mode.height *
				      rndr->mode.bitsPerPixel / 1);
	all->element2->pixels = malloc(rndr->mode.width * rndr->mode.height *
				       rndr->mode.bitsPerPixel / 1);
	all->s_snow = start_snow(rndr);
	all->s_slash = start_snow(rndr);
	return (all);
}

all_t	*set_all(sfVideoMode mode, all_t *all, render_t *rndr, char *str)
{
	all->a = 0;
	all->title = set_title(mode, all->title);
	all->load = set_load(mode, all->load);
	all->game = set_game(mode, all->game);
	all->esc = set_escape(mode, all->esc);
	all->trans = set_transition(all->trans);
	all->intro = set_intro(all->intro, mode, str);
	all->combat = set_combat(mode, all->combat);
	all->over = set_gameover(mode, all->over);
	all->pause = set_pause(mode, all->pause);
	set_particles(all, rndr);
	return (all);
}
