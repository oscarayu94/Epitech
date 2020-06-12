/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

pause_t	set_pause(sfVideoMode mode, pause_t pause)
{
	pause.pause = draw_pause(mode);
	pause.invi = draw_invi(mode);
	pause.skills = draw_skills(mode);
	pause.party = draw_party(mode);
	pause.save = draw_save(mode);
	pause.loadrect = draw_loadrect(mode);
	pause.preturn = draw_preturn(mode);
	pause.hud = draw_hud(mode);
	pause.inv = draw_inv(mode);
	pause.slots = draw_items2(mode);
	pause.slot1 = draw_slot1(mode);
	pause.slot2 = draw_slot2(mode);
	pause.slot3 = draw_slot3(mode);
	pause.helm = draw_helm(mode);
	pause.chest = draw_chest(mode);
	pause.bpa = draw_backpack(mode);
	pause.bpai = draw_backpacki(mode);
	pause.legs = draw_legs(mode);
	pause.arms = draw_arms(mode);
	pause.weapon = draw_weapon(mode);
	pause.eqin = draw_eqin(mode);
	pause.stat = draw_status(mode);
	pause.istat = draw_istat(mode);
	pause.sloti = draw_invi_slot(mode);
	pause.heal = draw_healty(mode);
	pause.hnum = draw_hnumber(mode);
	pause.hnumf = draw_hnumberf(mode);
	pause.empty = draw_empty(mode);
	pause.empty2 = draw_empty2(mode);
	pause.empty3 = draw_empty3(mode);
	pause.empty4 = draw_empty4(mode);
	pause.empty5 = draw_empty5(mode);
	pause.empty6 = draw_empty6(mode);
	pause.pvset.width = mode.width;
	pause.pvset.height = mode.height;
	pause.text = desc_slots(mode);
	pause.text2 = desc_backpack(mode);
	pause.maintenance = draw_maintenance();
	pause.pview = sfView_createFromRect(pause.pvset);
	return (pause);
}
