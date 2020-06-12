/*
** EPITECH PROJECT, 2017
** emacs
** File description:
** task06
*/

int	my_is_prime(int nb)
{
	int	i;
	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	if (i == nb)
		return (1);
}
