/*
** EPITECH PROJECT, 2018
** putchar rebirth
** File description:
** Rebirth
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
