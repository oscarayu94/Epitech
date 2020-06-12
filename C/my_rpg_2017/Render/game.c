/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

game_t	render_game(render_t rndr, game_t game)
{
	sfRenderWindow_clear(rndr.window, sfBlack);
	sfView_setCenter(game.view, sfRectangleShape_getPosition(game.mc));
	game.clock = clock_config(game.clock);
	game = mov_char(game, 2);
	sfRenderWindow_drawSprite(rndr.window, game.bg, NULL);
	sfRenderWindow_drawRectangleShape(rndr.window, game.mc, NULL);
	sfRenderWindow_setView(rndr.window, game.view);
	return (game);
}
