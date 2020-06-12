/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main
*/

//clientJ2T3 -h <ip> -p <port>

#include "client.h"

void *begin_network(void *network)
{
    int client_socket;
    int ok = 0;
    struct sockaddr_in address;
    my_info_t* tmp = (my_info_t*) network;
    char *buffer = malloc(sizeof(char) * 1024);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("socket: ");
    }
    address.sin_addr.s_addr = inet_addr(tmp->host_c);
    address.sin_port = htons(tmp->port);
    address.sin_family = AF_INET;
    if (connect(client_socket, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("connection failed");
    }
    else {
        int z = read(client_socket,buffer,1024);
        buffer[z] = '\0';
        printf("Server said: %s\n", buffer);
        bzero(buffer,1024);
        char *id_greet = strdup("ID\n");
        send(client_socket,id_greet, strlen(id_greet), 0);
        printf("On envoie : [%s]\n", id_greet);
        char *buffer_id = malloc(sizeof(char) * 1024);
        z = read(client_socket,buffer_id,1024);
        printf("Le server a envoye %d bytes\n", z);
        buffer_id[z] = '\0';
        printf("id = [%s]\n",buffer_id);
        if(buffer_id[0] == 'I' && buffer_id[1] =='D'){
            ok = 1;
        }
        if(ok == 1) {
            char *map = strdup("MAP\n");
            send(client_socket,map,strlen(map),0);
        }
        bzero(buffer_id,6);
    }        
    printf("Thread?\n");
    return NULL;
}

int go_forth(char **argv, my_info_t *info)
{
    pthread_t network;   
    pthread_t graphical_interface;
    if (pthread_create(&graphical_interface,NULL,begin_graphical_interface, &graphical_interface) == -1){
        fprintf(stderr, "Error creating thread\n");
        return (84);
    }
    if (pthread_create(&network,NULL,begin_network, info) == -1){
        fprintf(stderr, "Error creating thread\n");
        return (84);
    }
    pthread_join(network, NULL);
    pthread_join(graphical_interface, NULL);
    return(0);
}

int check_arguments(char** argv, my_info_t *info)
{
    if (strcmp(argv[1],"-h") != 0){
        printf ("Invalid -h argument\n");
        return (84);
    }
    if (strcmp(argv[3], "-p") != 0){
        printf ("Invalid -p argument\n");
        return (84);
    }
    if ((strcmp(argv[2], "localhost") != 0) && (strcmp(argv[2], "127.0.0.1") != 0)){
        printf ("Invalid host\n");
        return (84);
    }
    if (strcmp(argv[2],"localhost") == 0)
        info->host_c = strdup("127.0.0.1");
    else
        info->host_c = strdup(argv[2]);
    //if (atoi(argv[4]) == -1)
    info->port = atoi(argv[4]);
    // else {
    //     fprintf(stderr,"This port does not exist\n");
    //     return(84);
    // }
    go_forth(argv, info);
    return(0);
}

int main (int ac, char** argv)
{
    my_info_t *info = malloc(sizeof(struct my_info_s));
    if (ac != 5)
        return (84);
    else 
        check_arguments(argv,info);
}