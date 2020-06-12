/*
** EPITECH PROJECT, 2017
** Example about motherfucking read
** File description:
** Welp, see how this works and let's try things. Like always
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int nread;
    char buffer[128];
    
    nread=read(0,buffer,128);
    
    if(nread == -1)
     write(2,"an read error occured\n",26);
     
    if((write(1,buffer,nread))!= nread)
       write(2,"a write error occured\n",27);
    
    return 0;
} 
