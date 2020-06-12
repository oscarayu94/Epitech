/*
** EPITECH PROJECT, 2018
** pause_slots
** File description:
** 
*/

#include "../list.h"

sfRectangleShape	*draw_items2(sfVideoMode mode)
{
	sfRectangleShape	*slots;
	sfVector2f	size = {1000 , 1000};
	sfVector2f	pos = {700, 25};

	slots = sfRectangleShape_create();
	sfRectangleShape_setPosition(slots, pos);
	sfRectangleShape_setSize(slots, size);
	sfRectangleShape_setTexture(slots,
				    sfTexture_createFromFile("Img/itemsslots.png",
							     NULL), sfTrue);
	return (slots);
}

sfRectangleShape	*draw_slot1(sfVideoMode mode)
{
	sfRectangleShape	*slot1;
	sfVector2f	size = {105 , 115};
	sfVector2f	pos = {735, 60};

	slot1 = sfRectangleShape_create();
	sfRectangleShape_setPosition(slot1, pos);
	sfRectangleShape_setSize(slot1, size);
	sfRectangleShape_setTexture(slot1,
				    sfTexture_createFromFile("Img/items_mint_tea.png",
							     NULL), sfTrue);
	return (slot1);
}

sfRectangleShape	*draw_slot2(sfVideoMode mode)
{
	sfRectangleShape	*slot2;
	sfVector2f	size = {105 , 115};
	sfVector2f	pos = {870, 60};

	slot2 = sfRectangleShape_create();
	sfRectangleShape_setPosition(slot2, pos);
	sfRectangleShape_setSize(slot2, size);
	sfRectangleShape_setTexture(slot2,
				    sfTexture_createFromFile("Img/items_pineapple_juice.png",
							     NULL), sfTrue);
	return (slot2);
}

sfRectangleShape	*draw_slot3(sfVideoMode mode)
{
	sfRectangleShape	*slot3;
	sfVector2f	size = {105 , 115};
	sfVector2f	pos = {1005, 60};

	slot3 = sfRectangleShape_create();
	sfRectangleShape_setPosition(slot3, pos);
	sfRectangleShape_setSize(slot3, size);
	sfRectangleShape_setTexture(slot3,
				    sfTexture_createFromFile("Img/items_old_feather.png",
							     NULL), sfTrue);
	return (slot3);
}

sfRectangleShape	*draw_invi_slot(sfVideoMode mode)
{
	sfRectangleShape	*sloti;
	sfVector2f	size = {105 , 115};
	sfVector2f	pos = {735, 60};

	sloti = sfRectangleShape_create();
	sfRectangleShape_setPosition(sloti, pos);
	sfRectangleShape_setSize(sloti, size);
	sfRectangleShape_setFillColor(sloti, sfTransparent);
	if (pos.x != 1) {
		sfRectangleShape_setOutlineThickness(sloti, 10);
		sfRectangleShape_setOutlineColor(sloti, sfRed);
	}
	else
		sfRectangleShape_setOutlineThickness(sloti, 0);
	return (sloti);
}

text_t  desc_slots(sfVideoMode mode)
{
	text_t	title;
	sfVector2f	pos = {mode.width / 2 - 230, mode.height / 2 - 150};
	sfColor	color;

	color = sfColor_fromRGBA(150, 0, 24, 255);
	title.font = sfFont_createFromFile("Fonts/title.otf");
	title.text = sfText_create();
	sfText_setFont(title.text, title.font);
	sfText_setCharacterSize(title.text, 50);
	sfText_setColor(title.text, color);
	sfText_setPosition(title.text, pos);
	return (title);
}


int	move_key_slots(sfRectangleShape *invi, render_t rndr, pause_t pause, int a)
{
	sfVector2f	mov;
	sfVector2f	org = {405, 0};
	sfVector2f	org2 = {-405, 0};

	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		mov.x =- 135;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).x < 720) {
			sfRectangleShape_move(invi, org);
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		mov.x =+ 135;
		sfRectangleShape_move(invi, mov);
		if (sfRectangleShape_getPosition(invi).x > 1100) {
			sfRectangleShape_move(invi, org2);
		}
	}
	return (a);	
}
