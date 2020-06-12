/*
** EPITECH PROJECT, 2017
** Step2
** File description:
** Specific message acording to the read return
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void fs_understand_return_of_read (int fd, char *buffer, int size)
{
	int nread;

	nread = read(fd, buffer, size);
	
	if (fd == -1)
	{	write(1,"read failed\n",12);
		{
			if (fd < size)
				write(1,"read didn't complete the entire buffer\n",40);
			if (fd >= size)
				write(1,"read completed the entire buffer\n",30);
		}
	}	
	else if (fd == 0)
	{	
		write(1,"read has nothing more to read\n",30);
		{
                        if (fd < size)
			        write(1,"read didn't complete the entire buffer\n",40);
			if (fd >= size)
                        	write(1,"read completed the entire buffer\n",30);
		}
	}	
}

void call_fs(char const *filepath)
{
	int fd;
	char *buffer;
	
	fd = open(filepath, O_RDONLY);
	fs_understand_return_of_read(fd, buffer,strlen(buffer));
	close(fd);
}

int	main()
{
	call_fs("./hol");

}
