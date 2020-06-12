/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

title_t	set_title(sfVideoMode mode, title_t title)
{
	title.load = draw_load(mode);
	title.start = draw_start(mode);
	title.exit = draw_exit(mode);
	title.title = draw_gametitle(mode);
	title.invi = invi(mode);
	return (title);
}
