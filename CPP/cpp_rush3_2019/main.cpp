/*
** EPITECH PROJECT, 2020
** main
** File description:
** cpp
*/

#include <iostream>
#include "MyGKrellm.hpp"

void run_ncurses()
{
    NcursesMode datas;

    datas.run();
}

void run_sfml()
{
    SfmlMode datas;

    datas.run();
}

void run(int mode)
{
    switch (mode) {
    case TEXT_MODE:
        run_ncurses();
        break;
    case GRAPHICAL_MODE:
        run_sfml(); 
        break;
    default:
        break;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
        if ((std::string)av[1] == (std::string)"-h") {
            print_help(av);
            return (0);
        }
    run(get_mode());
    return (0);
}