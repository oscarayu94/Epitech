/*
** EPITECH PROJECT, 2017
** Step1
** File description:
** Opens a read only file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int	fs_open_file(char const *filepath)
{
	int fd;
	fd = open(filepath, O_RDONLY);
	if ( fd == -1)
	{
		write(1,"FAILURE\n",9);
		return(errno);
	}
	else if ( fd >= 0)
	{
		write(1,"SUCCESS\n",9);
	}	
	close(fd);
	return(fd);
}

int	main()
{
	fs_open_file("./hol");

}
