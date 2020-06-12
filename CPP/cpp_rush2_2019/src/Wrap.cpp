/*
** EPITECH PROJECT, 2020
** cpp rush
** File description:
** wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(void)
{
    _content = nullptr;
    _isOpen = false;
    _title = "Wrap";
}

Object *Wrap::openMe(void)
{
    if (_isOpen == true)
        std::cerr << "Wrap is already open" << std::endl;

    Object *tmp = _content;

    _isOpen = true;
    _content = nullptr;
    return (tmp);
}

void Wrap::closeMe(void)
{
    if (_isOpen == false)
        std::cerr << "Wrap is already closed" << std::endl;
    _isOpen = false;
}

bool Wrap::isOpen(void) const { return (_isOpen); }

bool Wrap::hasContent(void) const { return (_content != nullptr); }
