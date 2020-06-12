/*
** EPITECH PROJECT, 2017
** Step3.c
** File description:
** You know what to do, boss. Get em!
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void	fs_cat_500_bytes (char const *filepath)
{
	int fd;
	int nread;
	char buffer[4096];
	int size;

	size = 0;
	if ((fd = open (filepath, O_RDONLY)) == -1)
	{
		printf("file does not exist ;/");
        }
	else if (fd >= 0)
	{
		int i = 0;
		size = read(fd, buffer, 4096);
		while (i < 500)
		{	
			printf("%c", buffer[i]);
			i++;
		}	
	}	
	close(fd);
}

int	main()
{
	fs_cat_500_bytes("./testingtext.txt");
}	
