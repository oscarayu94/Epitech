/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

escape_t	set_escape(sfVideoMode mode, escape_t esc)
{
        esc.empty = draw_esc_emptiness(mode);
        esc.back = draw_esc_return(mode);
        esc.exit = draw_esc_exit(mode);
	esc.invi = invi_pause(mode);
        esc.title = draw_escape_title(mode);
	esc.pview.width = mode.width;
	esc.pview.height = mode.height;
	esc.view = sfView_createFromRect(esc.pview);
	return (esc);
}
