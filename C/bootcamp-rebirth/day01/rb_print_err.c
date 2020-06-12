/*
** EPITECH PROJECT, 2018
** rb_print_err.c
** File description:
** rb_print_err rebirth
*/

// un seul appel a write
//afficher sur la sortie d’erreur la chaine de caractères passée en parametre

#include <unistd.h>

void	rb_print_err(char *c)
{
	int	i;

	i = 0;
	while ( c[i] != '\0')
	{
		write(2, &c[i], 1);
		i++;
	}
}	

