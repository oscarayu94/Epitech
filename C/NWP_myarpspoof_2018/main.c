/*
** EPITECH PROJECT, 2019
** NWP_myarpspoof_2018
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

void proceed_spoof(char **av)
{
    printf("Let's go! NIGGERS?!\n");
}

void print_broadcast()
{
    printf("Broadcast!\n");
}

void print_spoof()
{
    printf("Spoof\n");
}

int check_arguments(char **av)
{
    if (strcmp(av[4],"--printBroadcast")==0)
        print_broadcast();
    else if (strcmp(av[4],"--printSpoof")==0)
        print_spoof();
    else
        return (-1);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 4 || ac > 5)
        return (84);
    else if (ac == 4)
        proceed_spoof(av);
    else if (ac == 5)
        if (check_arguments(av)==-1) {
            printf("Wrong 4th argument\n");
            return(84);
        }
    return(0);
}