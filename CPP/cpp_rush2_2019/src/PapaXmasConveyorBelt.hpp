/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** conveyor belt
*/

#ifndef CONVEYOR_BELT_HPP_
#define CONVEYOR_BELT_HPP_

#include "IConveyorBelt.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class PapaXmasConveyorBelt: public IConveyorBelt {
public:
    PapaXmasConveyorBelt(void);
    void pressIn(void);
    void pressOut(void);
    Object *getBeltContent(void) const;
    void put(Object *toAdd);
    Object *take(void);
    void pushQueue(Wrap *) override;
};

#endif
