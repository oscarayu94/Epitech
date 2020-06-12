/*
** EPITECH PROJECT, 2018
** Cooking
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void	destroy_all(render_t rndr, button_t *button)
{
	sfRenderWindow_destroy(rndr.window);
	sfRectangleShape_destroy(button->rect);
}

button_t	*draw_start(void)
{
	button_t	*start;
	assets_t	strt_assets;
	float_t	strt;
	
	strt.sizex = 700;
	strt.sizey = 100;
	strt.posx = 200;
	strt.posy = 200;
	start = set_button(strt_assets, strt, sfGreen);
	return (start);
}

button_t	*draw_exit(void)
{
	button_t	*exit;
	assets_t	exit_assets;
	float_t	ext;
	
	ext.sizex = 700;
	ext.sizey = 100;
	ext.posx = 200;
	ext.posy = 400;
	exit = set_button(exit_assets, ext, sfRed);
	return (exit);
}

void	render_display(render_t rndr)
{
	sfVideoMode	mode = {1080, 800, 60};
	button_t	*start;
	button_t	*exit;

	start = draw_start();
	exit = draw_exit();
	rndr.window = sfRenderWindow_create(mode, "Cook", sfDefaultStyle, NULL);
	while (sfRenderWindow_isOpen(rndr.window)) {
		analyse_events(rndr);

		sfRenderWindow_clear(rndr.window, sfBlack);
		sfRenderWindow_drawRectangleShape(rndr.window, start->rect, NULL);
		sfRenderWindow_drawRectangleShape(rndr.window, exit->rect, NULL);
		sfRenderWindow_display(rndr.window);
	}
	destroy_all(rndr, start);
}

int	main(int ac, char **av)
{
	render_t	rndr;
	
	render_display(rndr);
}
