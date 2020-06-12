/*
** EPITECH PROJECT, 2018
** rekreke
** File description:
** rkekrr
*/

#include <stdio.h>

void	message()
{
	printf("Hola");
}

int	prueba(char *av)
{
	int	i;
	char	*a = "prueba";
	
	for (i = 0; av[i] != '\0'; i++) {
		if (av[i] != a[i])
			return (0);
	}
	return (1);
}
		
int	main(int ac, char **av)
{
	if (ac > 1) //Por si hay un argumento; ac = 1 ==> ./a.out
		if (prueba(av[1]) == 1) // av[1] es *av
			message();
}	
