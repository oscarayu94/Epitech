/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_transition(void)
{
	sfRectangleShape	*transition;
	sfVector2f	size = {270, 280};

	transition = sfRectangleShape_create();
	sfRectangleShape_setSize(transition, size);
	transition = rect_texture(transition, "Img/battle.png");
	return (transition);
}

text_t	draw_battle_begins(void)
{
	text_t	battle;

	battle.text = sfText_create();
	battle.font = sfFont_createFromFile("Fonts/title.otf");
	sfText_setFont(battle.text, battle.font);
	sfText_setString(battle.text, "COMBAT MODE...\n\tBEGINS");
	sfText_setCharacterSize(battle.text, 20);
	sfText_setColor(battle.text, sfBlack);
	return (battle);
}
