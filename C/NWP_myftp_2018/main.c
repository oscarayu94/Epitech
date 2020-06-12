/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** main
*/

#include <string.h>
#include <stdio.h>

void help_me()
{
    printf("USAGE:  ./myftp port path\n");
    printf("\tport  is the port number on which the server socket listens\n");
    printf("\tpath  is the path to the home directory for the Anonymous user\n");
}

int main (int ac, char **av)
{
    char *help = "-help";
    
    if (av[1] == NULL)
        return (84);
    else if (strcmp(av[1],help) == 0)
    {
        help_me();
        return (0);
    }
}