/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** toy
*/

#include "Toy.hpp"

Toy::Toy(const std::string &title, const std::string &isTakenString)
{
    _isTakenString = isTakenString;
    _title = title;
}

Toy::~Toy(void) {}

void Toy::isTaken(void) const
{
    std::cout << _isTakenString << std::endl;
}

std::string Toy::getTitle(void) const { return (_title); }
