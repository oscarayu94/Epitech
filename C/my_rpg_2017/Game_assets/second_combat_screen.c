/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_dust(void)
{
	sfRectangleShape	*anim;
	sfVector2f	size = {160, 160};

	anim = sfRectangleShape_create();
	sfRectangleShape_setSize(anim, size);
	sfRectangleShape_setTexture(anim,
				    sfTexture_createFromFile("Img/dust.png",
							     NULL), sfTrue);
	return (anim);
}

sfRectangleShape	*draw_combat(sfVideoMode mode)
{
	sfRectangleShape	*mc;
	sfVector2f	size = {120, 200};
	sfVector2f	pos;

	pos.x = mode.width - 450;
	pos.y = mode.height / 2 - 300;
	mc = sfRectangleShape_create();
	sfRectangleShape_setPosition(mc, pos);
	sfRectangleShape_setSize(mc, size);
	sfRectangleShape_setTexture(mc,
				    sfTexture_createFromFile("Img/Rowena_stance.png",
							     NULL), sfTrue);
	return (mc);
}

sfRectangleShape	*draw_attack(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {100, mode.height - 450};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/atk.png",
							     NULL), sfTrue);
	return (atk);
}

sfRectangleShape	*draw_skill(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {100, mode.height - 350};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/skills.png",
							     NULL), sfTrue);
	return (atk);
}

sfRectangleShape	*draw_skill1(sfVideoMode mode)
{
	sfRectangleShape	*atk;
	sfVector2f	size = {300, 100};
	sfVector2f	pos = {400, mode.height - 350};

	atk = sfRectangleShape_create();
	sfRectangleShape_setPosition(atk, pos);
	sfRectangleShape_setSize(atk, size);
	sfRectangleShape_setTexture(atk,
				    sfTexture_createFromFile("Img/block2.png",
							     NULL), sfTrue);
	return (atk);
}
