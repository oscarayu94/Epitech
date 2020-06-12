/*
** EPITECH PROJECT, 2017
** FPS_test
** File description:
** limits the FPS of something
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

struct framebuffer
{
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

#endif

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    // TODO you have to implemente this function.                                                                                                                                             
    // It creates a framebuffer structure and allocates the pixels array which                                                                                                                
    // contains your image.                                                                                                                                                                   
    // CAUTION: the program might receive SIGSEGV if it is not implemented.                                                                                                                   
}
void framebuffer_destroy(framebuffer_t *framebuffer)
{
    // TODO you have to implemente this function.                                                                                                                                             
    // It frees the framebuffer and the memory space used by the image.                                                                                                                       
}


int	main()
{
	framebuffer_t   *framebuffer;
	sfRenderWindow	*window;
	t_framebuffer	*fb;
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVideoMode mode = {200, 200, 32};
	
	
	
	window = sfRenderWindow_create(mode,"SFML window", sfResize | sfClose, NULL);
	framebuffer = framebuffer_create(200, 200);
	texture = sfTexture_create (200,200);
	sprite =  sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_setFramerateLimit(window, 30);

	while (sfRenderWindow_isOpen(window))
	{
                sfSprite_setTexture(sprite, texture, sfTrue);

                sfRenderWindow_drawSprite(window, sprite, NULL);

		sfRenderWindow_display(window);
	}

	framebuffer_destroy(framebuffer);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	sfRenderWindow_destroy(window);
        return (0);
}

   
