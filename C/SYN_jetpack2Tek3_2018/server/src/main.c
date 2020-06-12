/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main
*/

#include "server.h"

int read_map(char* argv)
{
    info_server_t info;
    int lines = 0;
    int characters = 0;
    char ch;
    char ch2;
    char ch3;
    FILE *fp;
    fp = fopen(argv,"r");
    if (fp == NULL){
        perror("Error while opening the file, remember that the map must be in the same directory as the binary\n");
        exit(84);
    }
    for(int i = 0; ((ch = getc(fp)) != EOF); i++)
    {
        if (ch == '\n')
            lines++; 
    }
    lines++;
    info.map = malloc(sizeof(char*) * lines);
    fp = NULL;
    fp = fopen(argv,"r");
    for (int i = 0; i < lines; i++)
    {
        characters = 0;
        for (int y = 0; ((ch2 = getc(fp)) != EOF); y++){
            characters++;
            if (ch2 == '\n')
                break;
        }
        info.map[i] = malloc(sizeof(char) * characters);
    }
    fp = NULL;
    fp = fopen(argv,"r");    
    for (int i = 0;i < lines; i++)
    {
        for (int y = 0; ((ch3 = fgetc(fp)) != EOF); y++){
            info.map[i][y] = ch3;
            if (ch3 == '\n')
                break;
        }
    }
    fclose(fp);
    return 0;
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        char c = str[i];
        write(1, &c,1);
    }
}

void listen_requests(int new_socket)
{
    static int id = 0;
    char *buffer = malloc(sizeof(char) * 1024);
    int z = read(new_socket, buffer, 1024);
    printf("On a lu %d caracteres\n", z);
    if (z < 0) exit(84);
    buffer[z] = '\0';
    //my_putstr(buffer);
    if (strcmp(buffer,"ID\n") == 0){
        printf("C'est rentre\n");
        bzero(buffer, z);
        id++;
        char *id_char = strdup("ID 1\n");
        // char *temp = malloc(sizeof(char)  * 2);
        // id_char[0] = 'I';
        // id_char[1] = 'D';
        // id_char[2] = ' ';
        // sprintf(temp,"%d", id);
        // id_char[3] = temp[0];
        // id_char[4] = '\n';
        // id_char[5] = '\0';
        int tmp = send(new_socket, id_char, strlen(id_char), 0);
        printf("J'ai envoye %d bytes\n", tmp);
        bzero(id_char,6);
    }
    else if (strcmp(buffer,"MAP\n") == 0){
        bzero(buffer,1024);
        printf("MAP DETECTED\n"); 
    }
}

void server_i(int serv_socket, struct sockaddr_in address)
{
    int new_socket;
    int client_socket[30];
    int addrlen = sizeof(struct sockaddr_in);
    fd_set active_fd_set, read_fd_set;
    int stat = 0;
    int sd;
    char *hello = ("Succesful connection with client\n");
    fd_set fds;

    while (1)
    {
        FD_ZERO(&fds);
        FD_SET(serv_socket, &fds); 
        int max_sd = serv_socket;
        // for ( int i = 0; i < 30; i++)
        // {
        //     sd = client_socket[i];
        //     if(sd > 0)
        //         FD_SET(sd, &fds);
        //     if(sd > max_sd)
        //         max_sd = sd;
        // }
        if (select(FD_SETSIZE, &fds, NULL, NULL, NULL) == -1)
        {
            perror("select:");
            exit(84);
        }
        // int listenfd = new_socket;
        if (FD_ISSET(serv_socket, &fds))
        {
            if ((new_socket = accept(serv_socket,(struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
            {
                perror("i refuse");
                exit(84);
            }
            else 
            {
                for (int i = 0; i<= 2; i++)
                {
                    if (client_socket[i] == 0)
                    {
                        client_socket[i] = new_socket;
                        break;
                    }    
                    send(new_socket , hello , strlen(hello) , 0 ); 
                    printf("Client connected\n");
                    listen_requests(new_socket); 
                }
            }
        }
    }
    close(new_socket);
    close(serv_socket);   
    //exit(0); 
}

void bind_socket(int serv_socket, info_server_t *info)
{
    struct sockaddr_in address;
    printf("a2\n");
    printf("%d\n", info->port);
    bzero( &address,sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(info->port);
    address.sin_addr.s_addr = INADDR_ANY; 
    if (bind(serv_socket, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("no bondage allowed");
        exit(84);
    }
    if (listen(serv_socket, 3) < 0)
    {
        perror("i'm deaf");
        exit(84);
    }
    printf("a3\n");
    int addrlen = sizeof(address);
    server_i(serv_socket, address);
}

int create_server()
{
    int opt = 1;
    int serv_socket;
    printf("a1\n");
    serv_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_socket == -1)
    {
        perror(" Socket: ");
        exit(84);
    }
    if( setsockopt(serv_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("serv_socket");
        exit(EXIT_FAILURE);
    }
    return(serv_socket);
}

int check_arguments(char** argv, info_server_t *info)
{
    if (strcmp(argv[1],"-p") != 0){
        printf ("Invalid -p argument\n");
        return (84);
    }
    //if (atoi(argv[2]))
        info->port = atoi(argv[2]);
    // else{
    //     printf("Wrong port\n");
    //     return (84);
    //}
    if (strcmp(argv[3], "-g") != 0){
        printf ("Invalid -g argument\n");
        return (84);
    }
    // if (atoi(argv[4]) == -1){
    //     printf ("Wrong gravity!\n");
    //     return (84);
    // }
    // else{
        info->gravity = atoi(argv[4]);
    //}
    if (strcmp(argv[5], "-m") != 0){
        printf ("Invalid -m argument\n");
        return (84);
    }
    read_map(argv[6]);
    int serv_socket = create_server();
    bind_socket(serv_socket,info);
    return(0);
}

int main (int ac, char** argv)
{
    info_server_t *info = malloc(sizeof(info_server_t*));
    if (ac != 7)
        return (84);
    else
        check_arguments(argv,info);
}