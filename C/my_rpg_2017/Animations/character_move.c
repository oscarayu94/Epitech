/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

game_t	move_up(game_t game, int nb)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		if (game.frame.left < 147)
			game.frame.left = 147;
		if (game.clock.sec >= 0.1) {
			game.frame.left = game.frame.left + 48;
			if (game.frame.left > 243)
				game.frame.left = 147;
			sfRectangleShape_setTextureRect(game.mc, game.frame);
			sfClock_restart(game.clock.clock);
		}
		game.mov.y = game.mov.y - nb;
		sfRectangleShape_setPosition(game.mc, game.mov);
		if (get_white_pixels(game.collide, game.mov, game.mc) == 0) {
			game.mov.y = game.mov.y + (nb + 1);
			sfRectangleShape_setPosition(game.mc, game.mov);
		}
	}
	return (game);
}

game_t	move_down(game_t game, int nb)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		if (game.clock.sec >= 0.1) {
			game.frame.left = game.frame.left + 48;
			if (game.frame.left > 99)
				game.frame.left = 3;
			sfRectangleShape_setTextureRect(game.mc, game.frame);
			sfClock_restart(game.clock.clock);
		}
		game.mov.y = game.mov.y + nb;
		sfRectangleShape_setPosition(game.mc, game.mov);
		if (get_white_pixels(game.collide, game.mov, game.mc) == 0) {
			game.mov.y = game.mov.y - (nb + 1);
			sfRectangleShape_setPosition(game.mc, game.mov);
		}
	}
	return (game);
}

game_t	move_right(game_t game, int nb)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		if (game.frame.left < 435)
			game.frame.left = 435;
		if (game.clock.sec >= 0.1) {
			game.frame.left = game.frame.left + 48;
			if (game.frame.left > 531)
				game.frame.left = 435;
			sfRectangleShape_setTextureRect(game.mc, game.frame);
			sfClock_restart(game.clock.clock);
		}
		game.mov.x = game.mov.x + nb;
		sfRectangleShape_setPosition(game.mc, game.mov);
		if (get_white_pixels(game.collide, game.mov, game.mc) == 0) {
			game.mov.x = game.mov.x - (nb + 1);
			sfRectangleShape_setPosition(game.mc, game.mov);
		}
	}
	return (game);
}

game_t	move_left(game_t game, int nb)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		if (game.frame.left < 291)
			game.frame.left = 291;
		if (game.clock.sec >= 0.1) {
			game.frame.left = game.frame.left + 48;
			if (game.frame.left > 387)
				game.frame.left = 291;
			sfRectangleShape_setTextureRect(game.mc, game.frame);
			sfClock_restart(game.clock.clock);
		}
		game.mov.x = game.mov.x - nb;
		sfRectangleShape_setPosition(game.mc, game.mov);
		if (get_white_pixels(game.collide, game.mov, game.mc) == 0) {
			game.mov.x = game.mov.x + (nb + 1);
			sfRectangleShape_setPosition(game.mc, game.mov);
		}
	}
	return (game);
}

game_t	mov_char(game_t game, int nb)
{
	game = move_up(game, nb);
	game = move_down(game, nb);
	game = move_right(game, nb);
	game = move_left(game, nb);
	return (game);
}
