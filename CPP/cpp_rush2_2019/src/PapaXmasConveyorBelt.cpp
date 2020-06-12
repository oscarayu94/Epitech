/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** a
*/

#include "PapaXmasConveyorBelt.hpp"

void PapaXmasConveyorBelt::pushQueue(Wrap *object)
{
    _queue.push_back(object);
}

IConveyorBelt *createConveyorBelt(void)
{
    IConveyorBelt *belt = new PapaXmasConveyorBelt;

    belt->pushQueue(new Box);
    belt->pushQueue(new GiftPaper);
    belt->pushQueue(new Box);
    belt->pushQueue(new GiftPaper);
    return (belt);
}

PapaXmasConveyorBelt::PapaXmasConveyorBelt(void)
{
    _content = nullptr;
}

Object *PapaXmasConveyorBelt::getBeltContent(void) const { return (_content); }

Object *PapaXmasConveyorBelt::take(void)
{
    Object *tmp = _content;

    _content = nullptr;
    return (tmp);
}

void PapaXmasConveyorBelt::put(Object *content)
{
    if (_content) {
        std::cerr << "Error: Cannot put - Belt already contains an object\n";
        return;
    }
    _content = content;
}

void PapaXmasConveyorBelt::pressIn(void)
{
    int size = _queue.size();

    if (_content || size == 0) {
        std::cerr << "Error: Cannot press IN - Belt already contains an object\n";
        return;
    }
    _content = _queue[size - 1];
    _queue.pop_back();
}

void PapaXmasConveyorBelt::pressOut(void)
{
    if (_queue.size() == 0) {
        std::cerr << "Error: belt not initialized\n";
        return;
    }
    std::cout << "Sending " << _content->getTitle() << " to Santa\n";
    // TODO XML
    _content = nullptr;
}
