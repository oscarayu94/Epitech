/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	enemy_turn(combat_t combat)
{
	if (combat.turn == 1) {
		combat.turn = -4;
		sfText_setString(combat.turn_name.text, "Enemy's turn");
	}
	return (combat);
}

combat_t	player_turn(combat_t combat, sfVector2i click)
{
	if (combat.turn == 0) {
		if (mouse_rect(combat.atk, click) == 1)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = -1;
		if (mouse_rect(combat.run, click) == 1)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = -7;
		if (mouse_rect(combat.skl, click) == 1)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = 2;
		if (mouse_rect(combat.item, click) == 1)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = 3;
		sfText_setString(combat.turn_name.text, "Rowena's turn");
	}
	return (combat);
}

combat_t	select_skill(combat_t combat, sfVector2i click)
{
	if (combat.turn == 2) {
		if (mouse_rect(combat.skl1, click) == 1 &&
		    combat.rowena.mp > 24)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = -3;
		if (mouse_rect(combat.skl2, click) == 1 &&
		    combat.rowena.mp > 99)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = -2;
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			combat.turn = 0;
	}
	return (combat);
}

combat_t	select_item(combat_t combat, sfVector2i click)
{
	if (combat.turn == 3) {
		if (mouse_rect(combat.pineapple, click) == 1 &&
		    combat.item1 != 0)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = -5;
		if (mouse_rect(combat.mint, click) == 1 &&
		    combat.item2 != 0)
			if (sfMouse_isButtonPressed(sfMouseLeft))
				combat.turn = -6;
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			combat.turn = 0;
	}
	return (combat);
}

combat_t	combat_scenarios(combat_t combat, sfVector2i click)
{
	combat = select_item(combat, click);
	combat = select_skill(combat, click);
	combat = player_turn(combat, click);
	combat = enemy_turn(combat);
	return (combat);
}
