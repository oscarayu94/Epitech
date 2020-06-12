/*
** EPITECH PROJECT, 2018
** clean_hunter
** File description:
** cleans assets of my_hunter
*/

#include "list.h"

void	clean_assets(game_t *game)
{
	sfRenderWindow_destroy(game->window);
	sfSound_destroy (game->sound);
	sfMusic_destroy (game->music);
	sfSoundBuffer_destroy (game->soundbuffer);
}	
