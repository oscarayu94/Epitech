/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_skill2(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {700, mode.height - 350};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/azure.png",
							     NULL), sfTrue);
	return (atk);
}

sfRectangleShape	*draw_items(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {100, mode.height - 250};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/items.png",
							     NULL), sfTrue);
	return (atk);
}

sfRectangleShape	*draw_pineapple(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {400, mode.height - 250};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/pineapple.png",
							     NULL), sfTrue);
	return (atk);
}

sfRectangleShape	*draw_mint(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {700, mode.height - 250};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/mint.png",
							     NULL), sfTrue);
	return (atk);
}

sfRectangleShape	*draw_potion(sfVideoMode mode)
{
	sfRectangleShape	*mc;
	sfVector2f	size = {192, 192};

	mc = sfRectangleShape_create();
	sfRectangleShape_setSize(mc, size);
	sfRectangleShape_setTexture(mc,
				    sfTexture_createFromFile("Img/potion.png",
							     NULL), sfTrue);
	return (mc);
}
