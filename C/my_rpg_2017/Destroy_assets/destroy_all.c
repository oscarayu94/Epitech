/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	destroy_all(all_t *all, render_t rndr)
{
	destroy_title(all->title);
	destroy_load(all->load);
	destroy_intro(all->intro);
	destroy_escape(all->esc);
	sfRenderWindow_destroy(rndr.window);
}
