/*
** EPITECH PROJECT, 2017
** grafic_testing2
** File description:
** A c file to test a grafic code seen in a video
*/

#include <stdlib.h>
#include <SFML/Config.h>
#include "display_framebuffer.h"

int	main()
{
	int	width;
	int	height;
	int	bitsPerPixel;

	sfUint8	*pixels;
	
	width = 500;
	height = 500;
	bitsPerPixel = 32;

	pixels = malloc(width * height * bitsPerPixel / 8);

	pixels[0] = 255;
	pixels[1] = 125;
	pixels[2] = 0;
	pixels[3] = 255;       
	
	display_framebuffer(pixels, width, height);
	
}

