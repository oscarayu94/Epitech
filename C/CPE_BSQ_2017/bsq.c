/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Find Biggest SQuare. Like and subscribe.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void	number_of_lines ()
{
	int count;
	char *str;
	int chk;

	chk = 0;
	count = 0;
	if (str[chk] == '\n')
	{
		count++;
		chk++;
	}
	printf ("%d\n", count);
}

int	lenght (int)
{
	// Debe contar el numero de caracteres totales en el tablero

	// Eso si, no debe contar los "\n"

	
}	

char	*read_archive (char *filepath)
{
	int fd;
	int i;
	char buffer[1];
	int size;
	char *str;
	int lengh;
	
	lengh = length(av[1]);
	str = malloc(sizeof(char) * lengh);
	i = 0;
	size = 0;
        if ((fd = open (filepath, O_RDONLY)) == -1)
	{
		write(1,"Wrong input. Please input a board.\n",30);
		return ("E");
	}
	else if (fd >= 0)
	{
		size = read(fd, buffer, 1);
		while(buffer[0] != '\n')
			size = read(fd,buffer,1);
		size = read(fd,buffer,1);
		while(size > 0)
		{
			str[i] = buffer[0];
			i++;
			size = read(fd,buffer,1);
		}
	}
	str[i] = '\0';
	close(fd);
	return(str);
}

int	main(int ac, char **av)
{
	char *str;
	
        str = read_archive(av[1]);
	return(0);
}
