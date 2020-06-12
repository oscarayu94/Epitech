/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

void	desc_armor(pause_t pause)
{
	if (sfRectangleShape_getPosition(pause.bpai).y == 150)
		sfText_setString(pause.text2.text, crimson_helmet());
	if (sfRectangleShape_getPosition(pause.bpai).y == 215)
		sfText_setString(pause.text2.text, crimson_chest());
	if (sfRectangleShape_getPosition(pause.bpai).y == 280)
		sfText_setString(pause.text2.text, crimson_arm());
	if (sfRectangleShape_getPosition(pause.bpai).y == 345)
		sfText_setString(pause.text2.text, crimson_leg());
	if (sfRectangleShape_getPosition(pause.bpai).y == 410)
		sfText_setString(pause.text2.text, dane_axe());
}

int	backpack_event(int a, render_t rndr, pause_t pause, sfVector2i click)
{
	a = analyse_equip(rndr, pause, a);
	desc_armor(pause);
	render_backpack(rndr, pause);
	return (a);
}
