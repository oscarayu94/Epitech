/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	desc_items(pause_t pause)
{
	if (detect_rect(pause.sloti, pause.slot1) == 1)
		sfText_setString(pause.text.text, mint_tea_description());
	if (detect_rect(pause.sloti, pause.slot2) == 1)
		sfText_setString(pause.text.text, pineapple_description());
	if (detect_rect(pause.sloti, pause.slot3) == 1)
		sfText_setString(pause.text.text, plume_description());
}

int	items_event(int a, render_t rndr, pause_t pause, sfVector2i click)
{
	a = analyse_slots(rndr, pause, a);
	desc_items(pause);
	render_items(rndr, pause);
	return (a);
}
