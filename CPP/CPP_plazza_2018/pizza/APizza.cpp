/*
** EPITECH PROJECT, 2019
** pizza
** File description:
** abstrac
*/

#include "APizza.hpp"

APizza::APizza(plazza::PizzaType type, plazza::PizzaSize size)
    : _time(0), _type(type), _size(size)
{
    //std::cout << "A piza has been made" << std::endl;
}

std::string APizza::getTypeName()
{
    std::string name;
    
    switch (_type) {
        case plazza::Regina:
            name = "Regina";
            break;
        case plazza::Margarita:
            name = "Margarita";
            break;
        case plazza::Americana:
            name = "Americana";
            break;
        case plazza::Fantasia:
            name = "Fantasia";
            break;
    }
    return name;
}

std::string APizza::getSizeName()
{
    std::string name;

    switch (_size) {
        case plazza::S:
            name = "S";
            break;
        case plazza::M:
            name = "M";
            break;
        case plazza::L:
            name = "L";
            break;
        case plazza::XL:
            name = "XL";
            break;
        case plazza::XXL:
            name = "XXL";
            break;
    }
    return name;
}
