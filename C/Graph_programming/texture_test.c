/*
** EPITECH PROJECT, 2017
** texture_test
** File description:
** Test to see how texturizing and sprites work
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

int	main()
{
	sfRenderWindow	*window;
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVideoMode     video_mode;

        video_mode.width = 571;
        video_mode.height = 237;
        video_mode.bitsPerPixel = 32;

        window = sfRenderWindow_create(video_mode,"My Window",sfDefaultStyle,NULL);
	texture = sfTexture_createFromFile("/home/omartinez/Pictures/sadork.png", NULL);
	sprite = sfSprite_create();

	while (sfRenderWindow_isOpen(window))
	{
		sfSprite_setTexture(sprite, texture, sfTrue);

		sfRenderWindow_drawSprite(window, sprite, NULL);

		sfRenderWindow_display(window);

	}

	sfRenderWindow_destroy(window);
	return (0);

}
