//This one is really to just test stuff

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int	jimmies_rustled2(char const *filepath)
{
	int try;
	try = open(filepath, 0_RDONLY);
	
}
	
void	jimmies_rustled (int fd, char *buffer, int size)
{

	jimmies_rustled;

	buffer[10];
       
	fd=read(0,buffer,10);
    
	if(fd == -1)
		write(2,"an read error occured\n",26);
     
	if((write(1,buffer,fd))!= fd)
		write(2,"a write error occured\n",27);
        
}

int	main()
{
	jimmies_rustled ("./holi");
}

