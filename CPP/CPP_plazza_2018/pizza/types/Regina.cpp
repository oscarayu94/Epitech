/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Regina
*/

#include "Regina.hpp"

Regina::Regina(plazza::PizzaType type, plazza::PizzaSize size)
    : APizza(type, size)
{
}

Regina::~Regina()
{
}


void Regina::print_pizza_info()
{
    std::cout << "_time:" << _time << ",  type:" << _type << ", size:" << _size << std::endl;
}