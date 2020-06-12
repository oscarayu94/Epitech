/*
** EPITECH PROJECT, 2018
** core.c
** File description:
** This is the core of my_hunter
*/

#include "list.h"

void	begin_game(game_t *game)
{
	create(game);
	sfSound_setBuffer (game->sound, game->soundbuffer);
	sfSound_play (game->sound);
	sfSound_setLoop (game->sound, sfTrue);
	game->clock = sfClock_create();
	while (sfRenderWindow_isOpen(game->window)){
		sfRenderWindow_setSize(game->window, game->size);
		sfRenderWindow_setFramerateLimit(game->window, 60);
		sfRenderWindow_clear(game->window, sfBlack);
		analyse_events(game->window,game->click, game->event,game);
		sfSprite_setTexture(game->sprite, game->texture, sfTrue);
		sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
		sfRenderWindow_drawSprite(game->window, game->sprite_duck, NULL);
		sfRenderWindow_display(game->window);
		game->time = sfClock_getElapsedTime(game->clock);
		game->seconds = game->time.microseconds / 1000000.0;
		move_duck(game->window, game);
	}
	clean_assets(game);
}
