/*
** EPITECH PROJECT, 2019
** main
** File description:
** by oriol
*/

#include "ftrace.h"
#include "list.h"

void run_ftrace(int ac, char **av)
{
    char    *path;

    path = get_path(av[1]);
    if (path == NULL) {
        fprintf(stderr, "File '%s' not found\n", av[1]);
        exit(84);
    }
    av[1] = path;
    fork_comand_name(av + 1);
}

int main(int ac, char **av)
{
    if (ac < 2 || av == NULL) {
        fprintf(stderr, "Usage: ftrace <command>\n");
        return (84);
    }
    signal(SIGINT, &handle_sig_int);
    run_ftrace(ac, av);
    return (0);
}
