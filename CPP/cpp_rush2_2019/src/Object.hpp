/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** object interface
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>

class Object {
public:
    virtual ~Object(void) {}
    std::string getTitle(void) const;
protected:
    std::string _title;
};

std::ostream &operator<<(std::ostream &s, Object *obj);

#endif
