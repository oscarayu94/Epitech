/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** graphical_interface
*/

#include "client.h"

void *begin_graphical_interface(void *graphical_interface)
{   
    sfWindow	*window;
	sfVideoMode	video_mode;

	video_mode.width = 800;
	video_mode.height = 800;
	video_mode.bitsPerPixel = 32;
	window = sfWindow_create(video_mode,"Jetpack to hell",sfDefaultStyle,NULL);
	while (sfWindow_isOpen(window))
	{
		sfWindow_display(window);
	}
	sfWindow_destroy(window);
    return NULL;
}