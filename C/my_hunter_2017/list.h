/*
** EPITECH PROJECT, 2018
** list
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct game_s 
{
	sfVideoMode     video_mode;
	sfRenderWindow  *window;
        sfEvent         event;
        sfTexture       *texture;
        sfSprite        *sprite;
	sfTexture	*texture_duck;
	sfSprite	*sprite_duck;
        sfSoundBuffer   *soundbuffer;
        sfSound         *sound;
        sfMusic         *music;
        sfMouseButton   click;
	sfIntRect	magic;
	sfClock		*clock;
	sfTime		time;
	float		seconds;
	sfVector2u	size;
}game_t;

void	my_putchar(char c);
int	my_putstr(char const *str);
int	my_strcmp(char *s1, char *s2);
void	begin_game(game_t *game);
void	clean_assets(game_t *game);
void	create(game_t *game);
void	analyse_events(sfRenderWindow *window, sfMouseButton click, sfEvent event, game_t *game);
void	move_duck(sfRenderWindow *window, game_t *game);
int	error(int ac, char **av);

#endif
