/*
** EPITECH PROJECT, 2020
** init
** File description:
** cpp
*/

#include "MyGKrellm.hpp"

void print_help(char **av)
{
    std::cout << "Usage:\n\t" << av[0] << std::endl;
}

int get_mode()
{
    std::string mode;
    CLEAR_TERM;
    while (true) {
        std::cout << "Choose display mode:\n\t1) Text\n\t2) Graphical" << std::endl;
        std::cin >> mode;
        if (mode == "1" || mode == "2")
            break;
        CLEAR_TERM;
    }
    CLEAR_TERM;
    return (std::stoi(mode));
}
