/*
** EPITECH PROJECT, 2019
** Input
** File description:
** By Luis Angel Macias de la Cruz
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "IComponent.hpp"

class Input : public nts::IComponent {
public:
    Input(std::string input, int value) {
        if (value == 1 || value == 0)
            _value = value;
        _input = input;
    }
    

protected:
private:
    std::string _input;
    int _value;
};

#endif /* !INPUT_HPP_ */
