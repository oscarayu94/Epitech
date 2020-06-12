/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** bootstrap
*/

#include "struct.h"

int check_host(my_info_t *info)
{   
    if(strcmp(info->host_c, "localhost") == 0)
        return(0);
    else
        printf("No such hostname: 'nonexistent hostname'\n");
    return(-1);
}

int boots(my_info_t *info)
{
    int sock;
    char buffer[255];
    struct iphdr ip;
    struct udphdr udp;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(info->port);
    address.sin_addr.s_addr = INADDR_ANY;
    int one = 1;
    char *i = "hello";

    ip.check = 0;
    ip.daddr = address.sin_addr.s_addr;
    ip.frag_off = 0;
    ip.id = htonl(54321);
    ip.ihl = 5;
    ip.protocol = 17;
    if (info->host_flag == 0)
        ip.saddr = inet_addr(info->host_c);
    else if (check_host(info) == 0)
        ip.saddr = inet_addr("127.0.0.1");
    else
        return (-1);
    ip.tos = 0;
    ip.tot_len = sizeof (struct iphdr) + sizeof (struct udphdr);
    ip.ttl = 255;
    ip.version = 4;

    udp.check = 0; 
    udp.dest = htons (8622);
    udp.len = htons (8);
    udp.source = htons(6666);

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)) == -1){
        perror(" Socket");
        return(-1);
    }
    if ((setsockopt(sock,IPPROTO_IP, IP_HDRINCL, &one, sizeof(one))) == -1)
    {
        perror("sockopt");
        return(-1);
    }
    // if (connect(sock, (struct sockaddr*)&address, sizeof(address)) < 0)
    // {
    //     perror("connection failed");
    //     return (84);
    // }
    if (sendto(sock,(char *)&i,ip.tot_len,MSG_CONFIRM,(struct sockaddr*)&address,sizeof(address)) < 0)
    {
        perror("send failed:");
        return(84);
    }
    printf("my_boots ok\n");
    return(0);
}