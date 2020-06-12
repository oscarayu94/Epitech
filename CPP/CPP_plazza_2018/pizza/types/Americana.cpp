/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Americana
*/

#include "Americana.hpp"

Americana::Americana(plazza::PizzaType type, plazza::PizzaSize size)
    : APizza(type, size)
{
}

Americana::~Americana()
{
}

void Americana::print_pizza_info()
{
    std::cout << "_time:" << _time << ",  type:" << _type << ", size:" << _size << std::endl;
}