/*
** EPITECH PROJECT, 2017
** my_runner_bootstrap
** File description:
** A bootstrap for what will surely be a nightmare
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Window/Event.h>
#include <stdio.h>

void	close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
}

void	analyse_events(sfRenderWindow *window, sfEvent event)
{
	sfMouseButton	button;

	while (sfRenderWindow_pollEvent(window, &event))
	{
		if (event.type == sfEvtClosed)
		{
			close_window(window);
		}
		
}

int	main()
{
	sfRenderWindow	*window;
	sfEvent		event;
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVideoMode	video_mode;
	sfSoundBuffer	*soundbuffer;
	sfSound		*sound;

	video_mode.width = 1280;
	video_mode.height  = 729;
	video_mode.bitsPerPixel = 32;

	window = sfRenderWindow_create(video_mode,"Rnner",sfDefaultStyle,NULL);
	texture = sfTexture_createFromFile("Undyne.png", NULL);
	sprite = sfSprite_create();
	soundbuffer = sfSoundBuffer_createFromFile ("songrunner.wav");
	sound = sfSound_create ();
	sfSound_setBuffer (sound, soundbuffer);
	sfSound_play (sound);
	sfSound_setLoop (sound, sfTrue);

	while (sfRenderWindow_isOpen(window))
	{
		sfSprite_setTexture(sprite, texture, sfTrue);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
		analyse_events(window, event);
	}

	sfRenderWindow_destroy(window);
	sfSound_destroy (sound);
	sfSoundBuffer_destroy (soundbuffer);
	return (0);
	
/*struct	game_object *create_object(const char *path_to_spritesheet, sfVector2f pos, sf IntRect rect);

sfSprite


sfTexture


sfVector2f


sfIntRect



void	destroy_object(struct game_object *obj) 
