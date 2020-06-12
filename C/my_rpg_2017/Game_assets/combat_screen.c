/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

sfRectangleShape	*draw_enemy(sfVideoMode mode)
{
	sfRectangleShape	*mob;
	sfVector2f	size = {240, 200};
	sfVector2f	pos;

	pos.x = 200;
	pos.y = mode.height / 2 - 300;
	mob = sfRectangleShape_create();
	sfRectangleShape_setPosition(mob, pos);
	sfRectangleShape_setSize(mob, size);
	sfRectangleShape_setTexture(mob,
				    sfTexture_createFromFile("Img/draco.png",
							     NULL), sfTrue);
	return (mob);
}

sfRectangleShape	*draw_atk_anim(void)
{
	sfRectangleShape	*anim;
	sfVector2f	size = {256, 256};

	anim = sfRectangleShape_create();
	sfRectangleShape_setSize(anim, size);
        sfRectangleShape_setTexture(anim,
                                    sfTexture_createFromFile("Img/slash.png",
                                                             NULL), sfTrue);
	return (anim);
}

sfRectangleShape	*draw_atk2_anim(void)
{
	sfRectangleShape	*anim;
	sfVector2f	size = {256, 256};

	anim = sfRectangleShape_create();
	sfRectangleShape_setSize(anim, size);
	sfRectangleShape_setTexture(anim,
				    sfTexture_createFromFile("Img/claw.png",
							     NULL), sfTrue);
	return (anim);
}

sfRectangleShape	*draw_skl_anim(void)
{
	sfRectangleShape	*anim;
	sfVector2f	size = {320, 320};

	anim = sfRectangleShape_create();
	sfRectangleShape_setSize(anim, size);
	sfRectangleShape_setTexture(anim,
				    sfTexture_createFromFile("Img/slash.png",
							     NULL), sfTrue);
	return (anim);
}

sfRectangleShape	*draw_skl2_anim(void)
{
	sfRectangleShape	*anim;
	sfVector2f	size = {160, 160};

	anim = sfRectangleShape_create();
	sfRectangleShape_setSize(anim, size);
	sfRectangleShape_setTexture(anim,
				    sfTexture_createFromFile("Img/shield.png",
							     NULL), sfTrue);
	return (anim);
}
