/*
** EPITECH PROJECT, 2017
** emacs
** File description:
** task07
*/
int     my_is_prime2(int nb)
{
        int     i;
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

int	my_find_prime_sup(int nb)
{
	int	i;
	i = nb;
	while(my_is_prime2(i) == 0)
		i++;
	return (i);
	
}
