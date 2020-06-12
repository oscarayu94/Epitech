/*
** EPITECH PROJECT, 2018
** requirement
** File description:
** requirement
*/

int	my_factrec_synthesis(int nb)
{
	int     tmp = nb;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	tmp = tmp * my_factrec_synthesis(nb - 1);
	return (tmp);
}

int	my_squareroot_synthesis(int nb)
{
	int	i = 0;

	while ((i * i) < nb)
		i++;
	if (((i * i) > nb) && ((i * i) > (nb - 1)))
		return (-1);
	else
		return (i);
}
