/*
** EPITECH PROJECT, 2019
** Components
** File description:
** By Luis Angel Macias de la Cruz
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IComponent.hpp"
#include <list>
#include <vector>
#include <map>
#include <algorithm>

class Component : public nts::IComponent {
public:
    Component();
    nts::Tristate    compute(std::size_t pin = 1);
    void    setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void    dump();
    Component   *getComponent() { return this; }
private:
    std::vector<size_t>   _pinSet;
};

#endif /* !COMPONENT_HPP_ */
