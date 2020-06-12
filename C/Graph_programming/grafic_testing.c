/*
** EPITECH PROJECT, 2017
** grafic_testing
** File description:
** Provides a c file for doing grafic tests
*/


#include <SFML/Graphics.h>
#include <stdlib.h>
/*
** framebuffer.h
*/
#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
#include <SFML/Graphics.h>
struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);
#endif    /* FRAMEBUFFER_H_ */
/*
** end of framebuffer.h
*/
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
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    // TODO you have to implemente this function.
    // It sets the color of the pixel (x, y), that is at the right index in the pixels array
    // of the framebuffer passed as parameter.
}
int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;
    framebuffer_t *framebuffer;
    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    /* Create the framebuffer */
    framebuffer = framebuffer_create(800, 600);
    /* Load a sprite to display (including its texture) */
    texture = sfTexture_create(800, 600);
    if (!texture)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    /* Link the texture to the sprite */
    sfSprite_setTexture(sprite, texture, sfTrue);
    /* Limit the window framerate */
    sfRenderWindow_setFramerateLimit(window, 30);
    /* Start the game loop */
    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            /* Close window : exit */
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        /* Draw the pixel at (100,100) in the framebuffer */
        my_put_pixel(framebuffer, 100, 100, sfRed);
        /* Update the texture from the pixels array of the framebuffer */
        sfTexture_updateFromPixels(texture, framebuffer->pixels, 800, 600, 0, 0);
        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);
        /* Draw the sprite */
        sfRenderWindow_drawSprite(window, sprite, NULL);
        /* Update the window */
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    framebuffer_destroy(framebuffer);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
