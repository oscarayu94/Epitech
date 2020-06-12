/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

game_t	set_game(sfVideoMode mode, game_t game)
{
	game.bg = draw_bg(mode);
	game.mc = draw_mc(mode);
	game.mov = sfRectangleShape_getPosition(game.mc);
	game.vset.width = 270;
	game.vset.height = 240;
	game.view = sfView_createFromRect(game.vset);
	game.frame.left = 3;
	game.frame.top = 0;
	game.frame.width = 34;
	game.frame.height = 52;
	sfRectangleShape_setTextureRect(game.mc, game.frame);
	game.clock.clock = sfClock_create();
	game.collide = sfImage_createFromFile("Img/island_collide_2.png");
	return (game);
}
