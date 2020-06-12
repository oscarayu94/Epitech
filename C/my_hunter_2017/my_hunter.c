/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** Creates a minigame of duck hunt
*/

#include "list.h"

void    create(game_t *game)
{
	game->video_mode.width = 1280;
        game->video_mode.height = 720;
        game->video_mode.bitsPerPixel = 32;
	game->size.x = 1280;
	game->size.y = 720;
	game->magic.width = 110;
	game->magic.height= 110;
	game->magic.top = 0;
	game->magic.left = 0;
        game->window = sfRenderWindow_create(game->video_mode,"Duck Hunt",sfDefaultStyle,NULL);
        game->texture = sfTexture_createFromFile("Sprites/stage.png", NULL);
        game->sprite = sfSprite_create();
	game->clock = sfClock_create();
	game->sprite_duck = sfSprite_create();	
	game->texture_duck = sfTexture_createFromFile("Sprites/spritesheet.png", NULL);
	sfSprite_setTexture(game->sprite_duck, game->texture_duck, sfTrue);
	sfSprite_setTextureRect(game->sprite_duck, game->magic);
	game->soundbuffer = sfSoundBuffer_createFromFile ("Sounds/song.wav");
        game->sound = sfSound_create ();
        game->click = sfMouseLeft;
}

void	analyse_events(sfRenderWindow *window, sfMouseButton click, sfEvent event, game_t *game)
{
	while (sfRenderWindow_pollEvent(game->window,&event)){
		if (event.type == sfEvtClosed){
			sfRenderWindow_close(window);
		}
	}
	if (sfMouse_isButtonPressed(game->click)){
		my_putstr("Mouse has been clicked.\n");
	}	
}

void	move_duck(sfRenderWindow *window, game_t *game)
{

	if (game->seconds > 0.05)
	{
		game->magic.left = game->magic.left + 110;
		if (game->magic.left > 220)
			game->magic.left = 0;
		sfSprite_setTextureRect(game->sprite_duck, game->magic);
		sfClock_restart(game->clock);
	}
}	

void	display_help()
{
	my_putstr("\n This program is a recreation of Duck Hunt made on C.\n You'll need a mouse to play it.\n Click on the ducks to score points, and try to get as much as you can.\n Good luck! \n \n");
}

int     main(int ac, char **av, char **env)
{
	game_t *game;

	if (error(ac, env) == 0)
		return (84);
	game = malloc(sizeof(*game));
	if (ac > 1){
		if (my_strcmp("-h", av[1]) == 0)
			display_help();
		else
			my_putstr("Wrong input. Use -h as help argument, or execute without arguments.\n");
	}			
	else{
		begin_game(game);
		return (0);
	}	
}
