/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	load_input(sfRectangleShape *invi, render_t rndr, load_t load, int a)
{
	if (detect_rect(invi, load.save1) == 1)
		if(sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 2;
	if (detect_rect(invi, load.save2) == 1)
		if(sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 2;
	if (detect_rect(invi, load.save3) == 1)
		if(sfKeyboard_isKeyPressed(sfKeyReturn))
			a = 2;
	if (detect_rect(invi, load.lreturn) == 1)
		if(sfKeyboard_isKeyPressed(sfKeyReturn))
			a = -1;
	return (a);
}
