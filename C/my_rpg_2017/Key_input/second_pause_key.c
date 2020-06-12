/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	return_slots(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		a = 3;
	return (a);
}

int	return_equip(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		a = 3;
	return (a);
}
