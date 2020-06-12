/*
** EPITECH PROJECT, 2017
** my_everything
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char const *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (0);
}

int	my_put_nbr(int nb)
{
	int	i;
	
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			i = nb % 10;
			nb = (nb - i) / 10;
			my_put_nbr(nb);
			my_putchar('0' + i);
		}
		else
			my_putchar('0' + nb % 10);
	}
	return (0);
}

int	my_strlen(char *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}
