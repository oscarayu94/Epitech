/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** toy class
*/

#ifndef TOY_HPP
#define TOY_HPP

#include "Object.hpp"

class Toy: public Object
{
protected:
    std::string _isTakenString;
public:
    Toy(const std::string &title, const std::string &isTakenString);
    virtual ~Toy(void);
    void isTaken(void) const;
    std::string getTitle(void) const;
};

#endif
