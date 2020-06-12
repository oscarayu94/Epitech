/*
** EPITECH PROJECT, 2018
** solstumper5
** File description:
** solostumper
*/

#include <unistd.h>

void	message()
{
	write (2, "You inputed a NULL, idiot\n",27);
}	

int	error_message(char *av)
{
	int	i;
	char	*a = "prueba";
	
	for (i = 0; av[i] != '\0'; i++) {
		if (av[i] != a[i])
			return (0);
	}
	return(1);
}

int	main(int ac, char **av)
{
	if (ac > 1) {
		if (error_message(av[1]) == 1) {
			message();
		}
	}
}	
