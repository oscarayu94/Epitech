/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

int	pause_key(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyP))
		a = 3;
	return (a);
}

int	return_game(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyP))
		a = 2;
	return (a);
}

int	escape_game(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		a = 4;
	return (a);
}

int	escape_return(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		a = 2;
	return (a);
}

int	return_menu(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		a = 3;
	return (a);
}
