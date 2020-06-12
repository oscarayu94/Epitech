/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

load_t	set_load(sfVideoMode mode, load_t load)
{
        load.offmov.x = -120;
        load.offmov.y = 0;
        load.set.x = 530;
        load.set.y = 190;
	load.clock.clock = sfClock_create();
	load.empty = draw_emptiness(mode);
	load.table = draw_table(mode);
	load.save1 = draw_save_one(mode);
	load.save2 = draw_save_two(mode);
	load.save3 = draw_save_three(mode);
	load.lreturn = draw_lreturn(mode);
	load.text = draw_loadtitle(mode);
	load.invi = invi_load(mode);
	return (load);
}
