/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** object
*/

#include "Object.hpp"

std::string Object::getTitle(void) const { return (_title); }

std::ostream &operator<<(std::ostream &s, Object *obj)
{
    s << obj->getTitle();
    return (s);
}
