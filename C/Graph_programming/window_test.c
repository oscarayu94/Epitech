/*
** EPITECH PROJECT, 2017
** window_test
** File description:
** It's a window test
*/

#include <SFML/Graphics/RenderWindow.h>

int	main()
{
	sfRenderWindow	*window;
	sfVideoMode	video_mode;

	video_mode.width = 800;
	video_mode.height = 800;
	video_mode.bitsPerPixel = 32;

	window = sfRenderWindow_create(video_mode,"My Window",sfDefaultStyle,NULL);
				      
	while (sfRenderWindow_isOpen(window))
	{
		sfRenderWindow_display(window);
		sfRenderWindow_clear(window, sfWhite);
	}
	sfRenderWindow_destroy(window);
	return (0);
}




	
