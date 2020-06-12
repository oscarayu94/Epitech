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

//AF_INET flag for Ipv4

int main(int ac, char **av)
{
    int serv_socket;
    struct sockaddr_in address;
    int new_socket;
    int addrlen = sizeof(struct sockaddr_in);
    char *hello = strdup("Hello there!\n");

    serv_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_socket == -1)
    {
        perror("socket: ");
        return (84);
    }
    //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(av[1]));
    address.sin_addr.s_addr = INADDR_ANY; 
    if (bind(serv_socket, (struct sockaddr *)&address, sizeof(address)))
    {
        perror("no bondage allowed");
        return (84);
    }
    if (listen(serv_socket, 3) < 0)
    {
        perror("i'm deaf");
        return (84);
    }
    while (1)
    {
        if ((new_socket = accept(serv_socket,(struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("i refuse");
            return (84);
        } else {
            send(new_socket , hello , strlen(hello) , 0 ); 
            printf("Hello message sent\n"); 
        }
    // In the code of your server, add an infinite loop that will:
    // Call accept
    // Display the connection information
    // Write to the socket
    // Close the socket
        close(new_socket);
    }
    close(serv_socket);
    return 0; 
}