/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

combat_t	set_combat_menu(sfVideoMode mode, combat_t combat)
{
	combat.atk = draw_attack(mode);
	combat.skl = draw_skill(mode);
	combat.skl1 = draw_skill1(mode);
	combat.skl2 = draw_skill2(mode);
	combat.item = draw_items(mode);
	combat.pineapple = draw_pineapple(mode);
	combat.mint = draw_mint(mode);
	combat.potion = draw_potion(mode);
	combat.mana = draw_potion(mode);
	combat.run = draw_run(mode);
	combat.hp = draw_hp(mode);
	combat.mp = draw_mp(mode);
	combat.name = draw_name(mode);
	combat.enemy_hp = 200;
	combat.turn_name = draw_turn(mode);
	combat.hp_bar = draw_fiend_hp(mode);
	return (combat);
}

combat_t	set_char_stats(combat_t combat)
{
	combat.rowena.atk = 10;
	combat.rowena.hp = 230;
	combat.rowena.def = 70;
	combat.rowena.mp = 250;
	return (combat);
}

combat_t	set_combat_animation(combat_t combat)
{
	combat.clock.clock = sfClock_create();
	combat.anim.clock = sfClock_create();
	combat.atk_anim = draw_atk_anim();
	combat.atk2_anim = draw_atk2_anim();
	combat.skl_anim = draw_skl_anim();
	combat.skl2_anim = draw_skl2_anim();
	combat.dust = draw_dust();
	return (combat);
}

combat_t	set_combat_view(sfVideoMode mode, combat_t combat)
{
	combat.pview.width = mode.width;
	combat.pview.height = mode.height;
	combat.view = sfView_createFromRect(combat.pview);
	return (combat);
}

combat_t	set_animation_position(combat_t combat)
{
	sfRectangleShape_setPosition(combat.atk_anim, sfRectangleShape_getPosition(combat.enemy));
        sfRectangleShape_setPosition(combat.skl_anim, sfRectangleShape_getPosition(combat.enemy));
        sfRectangleShape_setPosition(combat.skl2_anim, sfRectangleShape_getPosition(combat.mc));
        sfRectangleShape_setPosition(combat.atk2_anim, sfRectangleShape_getPosition(combat.mc));
	sfRectangleShape_setPosition(combat.potion, sfRectangleShape_getPosition(combat.mc));
	sfRectangleShape_setPosition(combat.mana, sfRectangleShape_getPosition(combat.mc));
	sfRectangleShape_setPosition(combat.dust, sfRectangleShape_getPosition(combat.mc));
	return (combat);
}

combat_t	set_combat(sfVideoMode mode, combat_t combat)
{
	combat = set_combat_view(mode, combat);
	combat.enemy = draw_enemy(mode);
	combat.mc = draw_combat(mode);
	combat = set_combat_menu(mode, combat);
	combat.turn = 0;
	combat.shield = 0;
	combat.draco_frame.left = 3;
	combat.draco_frame.top = 0;
	combat.draco_frame.width = 87;
	combat.draco_frame.height = 100;
	combat = set_combat_animation(combat);
	combat = set_animation_position(combat);
	combat = set_char_stats(combat);
	combat.animate.frame.left = 0;
	combat.animate.frame.top = 0;
	combat.animate.frame.width = 136;
	combat.animate.frame.height = 164;
	
	combat.animate.frame2.left = 0;
	combat.animate.frame2.top = 0;
	combat.animate.frame2.width = 191;
	combat.animate.frame2.height = 182;

	combat.animate.frame3.left = 0;
	combat.animate.frame3.top = 0;
	combat.animate.frame3.width = 192;
	combat.animate.frame3.height = 192;

	combat.animate.frame4.left = 0;
	combat.animate.frame4.top = 0;
	combat.animate.frame4.width = 77;
	combat.animate.frame4.height = 65;

	combat.animate.frame5.left = 0;
	combat.animate.frame5.top = 0;
	combat.animate.frame5.width = 164;
	combat.animate.frame5.height = 203;

	sfRectangleShape_setTextureRect(combat.atk_anim, combat.animate.frame);
	sfRectangleShape_setTextureRect(combat.skl_anim, combat.animate.frame);
	sfRectangleShape_setTextureRect(combat.skl2_anim, combat.animate.frame2);
	sfRectangleShape_setTextureRect(combat.potion, combat.animate.frame3);
	sfRectangleShape_setTextureRect(combat.mana, combat.animate.frame3);
	sfRectangleShape_setTextureRect(combat.dust, combat.animate.frame4);
	sfRectangleShape_setTextureRect(combat.atk2_anim, combat.animate.frame5);
	combat.item1 = 2;
	combat.item2 = 2;
	combat.invc = invi_combat(mode);;
	return (combat);
}
