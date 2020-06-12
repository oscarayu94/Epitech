/*
** EPITECH PROJECT, 2017
** emacs
** File description:
** task05
*/

int	my_compute_square_root(int nb)
{
	int	i;
	i = 1;
	while (i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
