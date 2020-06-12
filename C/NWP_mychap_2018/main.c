/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** main
*/

#include "struct.h"

int help(char *str)
{
    if ((strcmp(str, "-h") == 0)) {
        printf("\tUSAGE\n\n");
        printf("\t./client -t host -p port -P password\n");
        printf("\tHost can be either a ip number or localhost, any other argument will be refused\n");
        return(0);
    }
    return(-1);
}

int check_args(char **av)
{   
    if ((strcmp(av[1], "-t") != 0))
        return(-1);
    if ((strcmp(av[3], "-p") != 0))
        return(-1);
    if ((strcmp(av[5], "-P") != 0)) 
        return(-1);
    return(0);
}

int is_number(char *str)
{   
    int lenght = strlen(str);
    int i;
    for (i=0;i<lenght; i++)
    {
        if (!isdigit(str[i]))
            return(-1);
    }
    return(0);
}

int fill_info(char **av, my_info_t **dest)
{
    my_info_t *info;
    if (is_number(av[2]) == 0){
        info->host_flag = 0;
        info->host_c = av[2];
    }
    else {
        info->host_flag = 1;
        info->host_c = av[2];
    }
    if (is_number(av[4]) == 0)  {  
        info->port = atoi(av[4]);
    }
    else
        return (-1);
    info->password = av[6];
    *dest = info;
    return (0);
}

int main(int ac, char **av)
{
    my_info_t *info = malloc(sizeof(my_info_t*));
    if (ac < 7){ 
        if (ac == 2)
            if (help(av[1]) == 0)
                return(84);
        printf("Incorrect use. Try ./client -h\n");
        return(84);
    }
    if (check_args(av) == -1) {
        printf("wrong arguments\n");
        return(84);
    }
    if (fill_info(av, &info) == -1) {
        printf("wrong info\n");
        return(84);
    }
    if (boots(info) == -1) {
        printf("my_boots failed\n");
        return(84);
    }
    printf("ok\n");
    return(0);
}