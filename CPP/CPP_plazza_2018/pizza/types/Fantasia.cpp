/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Fantasia
*/

#include "Fantasia.hpp"

Fantasia::Fantasia(plazza::PizzaType type, plazza::PizzaSize size)
    : APizza(type, size)
{
}

Fantasia::~Fantasia()
{
}


void Fantasia::print_pizza_info()
{
    std::cout << "_time:" << _time << ",  type:" << _type << ", size:" << _size << std::endl;
}