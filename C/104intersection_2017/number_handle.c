/*
** EPITECH PROJECT, 2018
** Number_Handle
** File description:
** 
*/

#include "list.h"

int     DivideNbr(int nb)
{
        int     div;

        if (nb == 0)
                return (1);
        div = 1;
        while (nb >= div)
        {
                div = div * 10;
        }
        return (div / 10);
}

int	 Int_numbers (char *av)
{
        int     i;

        for (i = 0; av[i] != '\0'; i++)
        {
                if ((av[i] < '0' || av[i] > '9') &&\
                    av[i] != '+' && av[i] != '-')
                        exit (84);
        }
        return (1);
}

int PositiveNbr (char *av)
{
        int     i;

        for (i = 0; av[i] != '\0'; i++)
        {
                if ((av[i] < '0' || av[i] > '9') &&\
                    av[i] != '+')
                        exit (84);
        }
        return (1);
}

void nbrHandle(int ac, char **av)
{
        int     i;

        for (i = 1; i < ac-1; i++)
        {
                if(av[i][0] == '\0')
                        exit (84);
                if(Int_numbers(av[i]) == 0)
                        exit (84);
        }
        if(av[8][0] == '\0')
		exit (84);
        PositiveNbr(av[8]);
}

int     my_put_nbr(int nb)
{
        int     div;

        if(nb < 0)
        {
                my_putchar('-');
                nb = nb * -1;
        }
	div = DivideNbr(nb);
        while (div != 0)
        {
                my_putchar(nb / div + '0');
		nb = nb % div;
                div = div / 10;
        }
        return (0);
}


