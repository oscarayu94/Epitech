/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Margarita
*/

#include "Margarita.hpp"

Margarita::Margarita(plazza::PizzaType type, plazza::PizzaSize size)
    : APizza(type, size)
{
}

Margarita::~Margarita()
{
}


void Margarita::print_pizza_info()
{
    std::cout << "_time:" << _time << ",  type:" << _type << ", size:" << _size << std::endl;
}