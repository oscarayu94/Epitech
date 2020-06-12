/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** main
*/

#include "list.hpp"
#include "reception/Reception.hpp"
#include "utils/Utils.hpp"
Utils* Utils::instance = 0;

int main(int ac, char **av)
{
    Parse_input *input = new Parse_input;
    std::unique_ptr<Reception> ptr(new Reception);

    if (input->get_values(ac, av) == false) {
        std::cout << "Error parsing input\n";
        return 84;
    }
    ptr->set_input(input);
    ptr->infinity_loop();
}