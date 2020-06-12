/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** bootstrap
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ether.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <linux/if_packet.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/udp.h>
#include <linux/ip.h>
#include <arpa/inet.h>
//#include "struct.h"

int main(int ac, char **av)
{
    int sock;
    char buffer[255];
    struct iphdr ip;
    struct udphdr udp;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi("8080"));
    address.sin_addr.s_addr = INADDR_ANY;
    int one = 1;
    const int *val = &one;


    ip.check = 0;
    ip.daddr = address.sin_addr.s_addr;
    ip.frag_off = 0;
    ip.id = htonl(54321);
    ip.ihl = 5;
    ip.protocol = 17;
    ip.saddr = inet_addr("127.0.0.1");
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
        exit(84);
    }
    if ((setsockopt(sock,IPPROTO_IP, IP_HDRINCL, &one, sizeof(one))) == -1)
    {
        perror("sockopt");
        exit(84);
    }
    printf("ok\n");
}