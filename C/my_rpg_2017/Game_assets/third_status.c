/*
** EPITECH PROJECT, 2018
** second_status
** File description:
** 
*/

#include "../list.h"

sfRectangleShape	*draw_empty5(sfVideoMode mode)
{
	sfRectangleShape	*empty5;
	sfVector2f	size = {75, 50};
	sfVector2f	pos = {1640, 495};

	empty5 = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty5, pos);
	sfRectangleShape_setSize(empty5, size);
	sfRectangleShape_setTexture(empty5, sfTexture_createFromFile("Img/status_bonus_defense.png", NULL), sfTrue);
	return (empty5);
}

sfRectangleShape	*draw_empty6(sfVideoMode mode)
{
	sfRectangleShape	*empty6;
	sfVector2f	size = {75, 50};
	sfVector2f	pos = {1640, 390};

	empty6 = sfRectangleShape_create();
	sfRectangleShape_setPosition(empty6, pos);
	sfRectangleShape_setSize(empty6, size);
	sfRectangleShape_setTexture(empty6, sfTexture_createFromFile("Img/status_bonus_attack.png", NULL), sfTrue);
	return (empty6);
}
