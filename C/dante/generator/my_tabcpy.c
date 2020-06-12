/*
** EPITECH PROJECT, 2018
** my_tabcpy.c
** File description:
** Made by Oscar Ayuso
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char	**my_tabcpy( char **src)
{
	int i = 0;
	int j = 0;
        int lines = 0;
        int columns = 0;
        char **dest = NULL;

        while (src[i] != NULL)
        {
	        i++;
        }
        lines = i + 1;
        i = 0;
 	dest = malloc(sizeof(char *) * lines);
        while (src[i] != NULL)
        {
                columns = my_strlen(src[i]);
		dest[i] = malloc(sizeof(char) * columns);
	        while (src[i][j] != '\0')
                {
                        dest[i][j] = src[i][j];
		        j++;
		}
		j = 0;
                i++;
        }
	i++;
	src[i] = NULL;
	return(src);
}	


		
