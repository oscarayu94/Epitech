/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** testing
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/select.h>

//AF_INET flag for Ipv4

void seek_help()
{
    printf ("USAGE: ./myftp port path\n");
    printf ("port\tis the port number on which the server socket listens\n");
    printf ("path\tis the path to the home directory for the Anonymous user\n");
}

void server(const char* arg)
{
    int serv_socket;
    struct sockaddr_in address;
    int new_socket;
    int addrlen = sizeof(struct sockaddr_in);
    char *hello = strdup("Hello there!\n");
    pid_t   pid;
    fd_set active_fd_set, read_fd_set;
    int stat = 0;

    serv_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_socket == -1)
    {
        perror("socket: ");
        exit(84);
    }
    //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(arg));
    address.sin_addr.s_addr = INADDR_ANY; 
    if (bind(serv_socket, (struct sockaddr *)&address, sizeof(address)))
    {
        perror("no bondage allowed");
        exit(84);
    }
    if (listen(serv_socket, 3) < 0)
    {
        perror("i'm deaf");
        exit(84);
    }
    while (1)
    {   
        int listenfd = new_socket;
        fd_set fds;
        FD_ZERO(&fds);
        int fdmax = listenfd;
        FD_SET(serv_socket, &fds); 

        if (select(FD_SETSIZE, &fds, NULL, NULL, NULL) == -1)
        {
            perror("select:");
            exit(84);
        }
        
        if ((new_socket = accept(serv_socket,(struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("i refuse");
            exit(84);
        }
        
        else 
        {
            for (int i = 0; i<= fdmax; i++)
            {
                send(new_socket , hello , strlen(hello) , 0 ); 
                printf("Hello message sent\n"); 
                close(new_socket);    
            }
        }
        // pid = fork();
        // if (pid > 0)
        // {
        //     pid = waitpid(pid, &stat, 0);
        //     close(new_socket);
        // }
        // if (pid == 0)
        // {    
        //     send(new_socket , hello , strlen(hello) , 0 ); 
        //     printf("Hello message sent\n"); 
        //     close(new_socket);
        // } 
    }
    close(serv_socket);   
    exit(0); 
}
//select(FD_SET)

int main(int ac, char **av)
{
    if (ac < 1)
        return(84);
    else if ( ac == 2) {
        if (strcmp(av[1], "-help") == 0)
            seek_help();
        else
            server(av[1]);
    }
}
