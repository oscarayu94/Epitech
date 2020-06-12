/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "Object.hpp"
#include <vector>

class ITable {
public:
    virtual ~ITable(void) {};
    virtual void put(Object *toAdd) = 0;
    virtual Object *take(void) = 0;
    virtual std::string *look(void) const = 0;
protected:
    std::vector<Object *> _tableContent;
private:
};

#endif /* !ITABLE_HPP_ */
