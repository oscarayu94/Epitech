/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** box
*/

#include "Box.hpp"

Box::Box(void): Wrap()
{
    _title = "Box";
}

bool Box::wrapMeThat(Object *toWrap)
{
    if (_content || !_isOpen) {
        std::cerr << "First Box has to be opened" << std::endl;
        return (false);
    }
    _content = toWrap;
    std::cout << "tuuuut tuuut tuut\n";
    return (true);
}
