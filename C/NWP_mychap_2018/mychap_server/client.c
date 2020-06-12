/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** client
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int client_socket;
    struct sockaddr_in address;
    char buffer[255]; 

    client_socket = socket(AF_INET, SOCK_PACKET, 0);
    if (client_socket == -1)
    {
        perror("socket: ");
        return (84);
    }
    address.sin_port = htons(atoi(av[2]));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(av[1]);

    if (connect(client_socket, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("connection failed");
        return (84);
    }
    read(client_socket, buffer, 254);
    write(client_socket, buffer, 254);
    printf("Server said: %s", buffer);
    return 0;
}