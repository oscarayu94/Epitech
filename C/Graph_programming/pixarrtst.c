#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Config.h>



int     main()
{
        sfRenderWindow  *window;
        sfVideoMode     video_mode;
        int     width;
	int     height;
	int     bitsPerPixel;
	sfUint8 *pixels;

	
        video_mode.width = 500;
        video_mode.height = 500;
        video_mode.bitsPerPixel = 32;

        window = sfRenderWindow_create(video_mode,"Exercise1",sfDefaultStyle,NULL);

        while (sfRenderWindow_isOpen(window))
        {
		
		width = 500;
		height = 500;
		bitsPerPixel = 32;

		pixels = malloc(width * height * bitsPerPixel / 8);

		pixels[0] = 255;
		pixels[1] = 125;
		pixels[2] = 0;
		pixels[3] = 255;

		display_framebuffer(pixels, width, height);

                sfRenderWindow_display(window);
		
                sfRenderWindow_clear(window, sfWhite);
        }
        sfRenderWindow_destroy(window);
        return (0);
}


