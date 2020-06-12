/*
** EPITECH PROJECT, 2018
** backpack
** File description:
** 
*/

#include "../list.h"

sfRectangleShape	*draw_backpack(sfVideoMode mode)
{
	sfRectangleShape	*bpa;
	sfVector2f	size = {600, 600};
	sfVector2f	pos = {1300, 100};

	bpa = sfRectangleShape_create();
	sfRectangleShape_setPosition(bpa, pos);
	sfRectangleShape_setSize(bpa, size);
	sfRectangleShape_setTexture(bpa, sfTexture_createFromFile("Img/backpack_3.png", NULL), sfTrue);
	return (bpa);
}

sfRectangleShape	*draw_backpacki(sfVideoMode mode)
{
	sfRectangleShape	*bpai;
	sfVector2f	size = {528, 70};
	sfVector2f	pos = {1347, 150};

	bpai = sfRectangleShape_create();
	sfRectangleShape_setPosition(bpai, pos);
	sfRectangleShape_setSize(bpai, size);	
	sfRectangleShape_setFillColor(bpai, sfTransparent);
	if (pos.y != 1) {
		sfRectangleShape_setOutlineThickness(bpai, 5);
		sfRectangleShape_setOutlineColor(bpai, sfRed);
	}
	else
		sfRectangleShape_setOutlineThickness(bpai, 0);
	return (bpai);
}

text_t	desc_backpack(sfVideoMode mode)
{
	text_t	title;
	sfVector2f	pos = {mode.width / 2 + 385, mode.height / 2 - 10};

	title.font = sfFont_createFromFile("Fonts/title.otf");
	title.text = sfText_create();
	sfText_setFont(title.text, title.font);
	sfText_setCharacterSize(title.text, 20);
	sfText_setColor(title.text, sfWhite);
	sfText_setPosition(title.text, pos);
	return (title);
}

int	move_key_back(sfRectangleShape *bpai, render_t rndr,
		      pause_t pause, int a)
{
	sfVector2f	mov;	
	sfVector2f	org = {0, 325};
	sfVector2f	org2 = {0, -325};

	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		mov.y =- 65;
		sfRectangleShape_move(bpai, mov);
		if (sfRectangleShape_getPosition(bpai).y <= 100)
			sfRectangleShape_move(bpai, org);
	}	
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		mov.y =+ 65;
		sfRectangleShape_move(bpai, mov);
		if (sfRectangleShape_getPosition(bpai).y >= 475)
			sfRectangleShape_move(bpai, org2);
	}
	return (a);	
}
