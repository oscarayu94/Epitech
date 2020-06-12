/*
** EPITECH PROJECT, 2017
** event_test
** File description:
** C file to test diferent tipes of events.
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Window/Event.h>

int     main()
{
        sfRenderWindow  *window;
	sfEvent		event;
	sfTexture       *texture;
        sfSprite        *sprite;
        sfVideoMode     video_mode;
        sfSoundBuffer   *soundbuffer;
        sfSound         *sound;
	

        video_mode.width = 400;
        video_mode.height = 518;
        video_mode.bitsPerPixel = 32;

        window = sfRenderWindow_create(video_mode,"DEUS VULT",sfDefaultStyle,NULL);
        texture = sfTexture_createFromFile("/home/omartinez/Pictures/emprah.jpg", NULL);
        sprite = sfSprite_create();
        soundbuffer = sfSoundBuffer_createFromFile ("/home/omartinez/Downloads/Rand/emprah2.wav");
        sound = sfSound_create ();


        sfSound_setBuffer (sound, soundbuffer);

        sfSound_play (sound);
        sfSound_setLoop (sound, sfTrue);

        while (sfRenderWindow_isOpen(window))
        {

		while (sfRenderWindow_pollEvent(window, &event))
		{
                        if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}

		sfSprite_setTexture(sprite, texture, sfTrue);

                sfRenderWindow_drawSprite(window, sprite, NULL);

                sfRenderWindow_display(window);
        }

	
        sfRenderWindow_destroy(window);
        sfSound_destroy (sound);
        sfSoundBuffer_destroy (soundbuffer);
        return (0);

}
