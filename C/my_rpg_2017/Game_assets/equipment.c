/*
** EPITECH PROJECT, 2018
** equipment
** File description:
** 
*/

#include "../list.h"

sfRectangleShape	*draw_helm(sfVideoMode mode)
{
	sfRectangleShape	*helm;
	sfVector2f	size = {644, 654};
	sfVector2f	pos = {600, 20};

	helm = sfRectangleShape_create();
	sfRectangleShape_setPosition(helm, pos);
	sfRectangleShape_setSize(helm, size);
	sfRectangleShape_setTexture(helm, sfTexture_createFromFile("Img/armor_2.png", NULL), sfTrue);
	return (helm);
}

sfRectangleShape	*draw_chest(sfVideoMode mode)
{
	sfRectangleShape	*chest;
	sfVector2f	size = {170, 160};
	sfVector2f	pos = {845, 25};
	
	chest = sfRectangleShape_create();
	sfRectangleShape_setPosition(chest, pos);
	sfRectangleShape_setSize(chest, size);
	sfRectangleShape_setTexture(chest, sfTexture_createFromFile("Img/helm.png", NULL), sfTrue);
	return (chest);
}

sfRectangleShape	*draw_legs(sfVideoMode mode)
{
	sfRectangleShape	*legs;
	sfVector2f	size = {160, 160};
	sfVector2f	pos = {610, 235};
 
	legs = sfRectangleShape_create();
	sfRectangleShape_setPosition(legs, pos);
	sfRectangleShape_setSize(legs, size);
	sfRectangleShape_setTexture(legs, sfTexture_createFromFile("Img/arms.png", NULL), sfTrue);
	return (legs);
}

sfRectangleShape	*draw_arms(sfVideoMode mode)
{
	sfRectangleShape	*arms;
	sfVector2f	size = {155, 155};
	sfVector2f	pos = {850, 510};

	arms = sfRectangleShape_create();
	sfRectangleShape_setPosition(arms, pos);
	sfRectangleShape_setSize(arms, size);
	sfRectangleShape_setTexture(arms, sfTexture_createFromFile("Img/legs.png", NULL), sfTrue);
	return (arms);
}

sfRectangleShape	*draw_weapon(sfVideoMode mode)
{
	sfRectangleShape	*weapon;
	sfVector2f	size = {160, 300};
	sfVector2f	pos = {1080, 205};

	weapon = sfRectangleShape_create();
	sfRectangleShape_setPosition(weapon, pos);
	sfRectangleShape_setSize(weapon, size);
	sfRectangleShape_setTexture(weapon, sfTexture_createFromFile("Img/axe.png", NULL), sfTrue);
	return (weapon);
}

sfRectangleShape	*draw_eqin(sfVideoMode mode)
{
	sfRectangleShape	*eqin;
	sfVector2f	size = {155, 200};
	sfVector2f	pos = {850, 200};

	eqin = sfRectangleShape_create();
	sfRectangleShape_setPosition(eqin, pos);
	sfRectangleShape_setSize(eqin, size);
	sfRectangleShape_setTexture(eqin, sfTexture_createFromFile("Img/chest.png", NULL), sfTrue);
	return (eqin);
}
