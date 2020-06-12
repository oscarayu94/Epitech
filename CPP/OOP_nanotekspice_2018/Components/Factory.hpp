/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IComponent.hpp"
#include "Component.hpp"

class Factory {
public:
    std::unique_ptr<nts::IComponent>    createComponent(const std::string &type, const std::string &value);

protected:
private:
};

#endif /* !FACTORY_HPP_ */
