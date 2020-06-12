/*
** EPITECH PROJECT, 2018
** Cooking
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void	hello()
{
	my_putstr("Hello\n");
}

void    event_button(render_t render)
{
        button_t        *button;
        assets_t        assets;
        sfVector2i      click;
	float_t	flt;
	void (*callback)(void) = &hello;

	flt.sizex = 200;
	flt.sizey = 200;
	flt.posx = 300;
	flt.posy = 200;
        click = sfMouse_getPosition(render.screen);
        button = set_button(assets, flt, sfWhite);
        if (render.event.type == sfEvtMouseButtonPressed) {
		if (buttonIsClicked(button, click, assets, render) == 1)
                        callback();
        }
}

void	close_window(render_t render)
{
	if (render.event.type == sfEvtClosed)
		sfRenderWindow_close(render.window);
}

void	analyse_events(render_t rndr)
{
	while (sfRenderWindow_pollEvent(rndr.window, &rndr.event)) {
		close_window(rndr);
		event_button(rndr);
	}
}
