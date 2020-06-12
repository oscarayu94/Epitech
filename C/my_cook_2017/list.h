/*
** EPITECH PROJECT, 2018
** list H
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

#ifndef LIST_H_
#define LIST_H_

typedef struct button_s {
	sfRectangleShape	*rect;
}	button_t;

typedef struct menu_s {
	button_t	*start;
	button_t	*exit;
}	menu_t;

typedef struct render_s {
	sfRenderWindow	*window;
	sfEvent		*pevent;
	sfEvent		event;
	sfWindow	*screen;
}	render_t;

typedef struct assets_s {
	sfVector2f	pos;
	sfVector2f	size;
	sfColor	color;
}	assets_t;

typedef struct float_s {
	float	sizex;
	float	sizey;
	float	posx;
	float	posy;
}	float_t;

button_t	*buttonInitialise(assets_t assets);
button_t	*set_button(assets_t assets, float_t draw, sfColor color);
void	my_putchar(char c);
int	my_putstr(char const *str);
int	my_put_nbr(int nb);
int	my_strlen(char *str);
void	close_window(render_t render);
void	analyse_events(render_t rndr);
void	event_button(render_t render);
void	hello();
int	buttonIsClicked(button_t *button, sfVector2i clikPos, assets_t assets, render_t rndr);

#endif
