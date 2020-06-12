/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

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

typedef struct info_server_s {
    int port;
    int gravity;
    char** map;
} info_server_t;

#endif /* !SERVER_H_ */
