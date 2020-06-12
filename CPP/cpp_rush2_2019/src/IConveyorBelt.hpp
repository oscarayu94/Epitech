/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** IConveyorBelt
*/

#ifndef ICONVEYORBELT_HPP_
#define ICONVEYORBELT_HPP_

#include "Object.hpp"
#include "Wrap.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"
#include <vector>

class IConveyorBelt {
public:
    virtual ~IConveyorBelt(void) {}
    virtual void put(Object *toAdd) = 0;
    virtual Object *take(void) = 0;
    virtual void pushQueue(Wrap *) = 0;
protected:
    Object *_content;
    std::vector<Wrap *> _queue;
};

IConveyorBelt *createConveyorBelt(void);

#endif /* !ICONVEYORBELT_HPP_ */
