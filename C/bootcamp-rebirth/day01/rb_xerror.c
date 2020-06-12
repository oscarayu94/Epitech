/*
** EPITECH PROJECT, 2018
** rb_xerror.c
** File description:
** rb_xerror rebirth
*/

/*afficher sur la sortie d’erreur la chaine de caractères passée en paramètre précédée par la mention 
«Error: » puis quittera le programme en retournant 84. Note : un \n sera ajouté automatiquement
à la fin

Fonctions recommandes: rb_print_err ; exit . 

*/

#include <stdlib.h>
#include <unistd.h>

void	rb_print_error(char *c)
{
	int	i;

	i = 0;
	while ( c[i] != '\0')
	{
		write (2, &c[i], 1);
		i++;
	}
}	

void	rb_xerror(char *c)
{
	write (2, "Error:", 6);
	rb_print_error(c);
	write (2, "\n", 1);
	exit (84);
}

