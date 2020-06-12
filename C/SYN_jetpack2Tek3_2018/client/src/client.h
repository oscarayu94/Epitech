/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <pthread.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/select.h>

void *begin_graphical_interface(void *graphical_interface);

typedef struct my_info_s {
    char *host_c;
    int port;
} my_info_t;

#endif /* !MAIN_H_ */
