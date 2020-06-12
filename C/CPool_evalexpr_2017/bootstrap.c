/*
** EPITECH PROJECT, 2017
** bootstrap
** File description:
** Inaros
*/

#include <stdio.h>
#include <stdlib.h>

int	number(char **str)
{
        int     i;
        long    n;

        i = 0;
        n = 0;
       
        while (*str[i] != '\0')
        {
                if ((*str[i] < '0' || *str[i] > '9'))
                {
                        printf("There must be only numbers in the string");
                        n = n + *str[i] - 48;
			n = n * 10;
                        i++;
                }
		n = n / 10;
        
        }
	return(n);
}

int     my_getnbr(char *str)
{
        int     i;
        long    n;

        i = 0;
        n = 0;
        if (str[0] == '-')
                i++;
        while (str[i] != '\0')
        {
                if ((str[i] < '0' || str[i] > '9'))
                        printf("There must be only numbers in the string");
		n = n + str[i] - 48;
		n = n * 10;
		i++;
        }
	n = n / 10;
	if (str[0] == '-')
		n = n * -1;
	return (n);

}


int	my_strtol(char *str, char **endptr)
{
	long	c;
       	char	*ptr;
	int	i;
	int	g;
	int	h;
	
	c = 2;
	ptr = malloc(sizeof(char)*(50));
	h = 0;
	i = 0;
	g = 0;
	if (str[g] == '-')
	{
		g++;
	}	
	else if (str[g] == '+')
	{
		g++;
	}
	while (str[g] >= '0' || str[g] <= '9')
	{
		ptr[i] = str[g];
		i++;
		g++;
	}
	ptr[i] = '\0';
	c = my_getnbr(ptr);
	if (str[0] == '-')
		c = c * -1;
	while (str[g] != '\0')
	{
		(*endptr)[h] = str[g];
		h++;
		g++;
	}
	(*endptr) = '\0';
	return (c);
}

int	main(int ac, char **av)
{
	char *b;
        
	if (ac == 2)
	{
		my_strtol(av[1], &b);
	}	
	else
	{
		printf("Not valid\n");
	}
	return(0);
		
}


//ptr esta apuntando a algo que no existe, de ahi el crash.
