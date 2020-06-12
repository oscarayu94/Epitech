/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** struct
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
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#ifndef STRUCT_H_
    #define STRUCT_H_


// struct ipheader {
//     unsigned char   iph_ihl:5, /* Little-endian */
//                     iph_ver:4;
//     unsigned char   iph_tos;
//     unsigned short int  iph_len;
//     unsigned short int  iph_ident;
//     unsigned char       iph_flags;
//     unsigned short int iph_offset;
//     unsigned char   iph_ttl;
//     unsigned char   iph_protocol;
//     unsigned short int  iph_chksum;
//     unsigned int    iph_sourceip;
//     unsigned int    iph_destip;
// };

// struct udpheader {
//     unsigned short int udph_srcport;
//     unsigned short int udph_destport;
//     unsigned short int udph_len;
//     unsigned short int udph_chksum;
// };

typedef struct my_info_s {
    char *host_c;
    int host_flag;
    int port;
    char *password;
} my_info_t;

int boots(my_info_t *info);

#endif /* !STRUCT_H_ */
