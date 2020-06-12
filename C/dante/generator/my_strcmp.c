/*
** EPITECH PROJECT, 2018
** strcmp
** File description:
** Compares two strings.
*/

#include <stdio.h>
#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
	int i;
	for (i = 0; s1[i] != '\0'; i++) {
		if (s1[i] != s2[i])
			return (1);
	}
	//if (s1[i] == s2[i]);
		//return (1);
	// Esta parte deberia ser añadida para completa funcionalidad.
	return (0);
}
