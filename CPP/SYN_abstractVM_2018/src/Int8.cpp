/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Int8
*/

#include "../include/Int8.hpp"

Int8::Int8()
{
}

Int8::~Int8()
{
}

int Int8::getNb() const {
    return nb;
}

void Int8::setNb(int number)  {
    nb = number;
}

std::string Int8::toString() const{

}

IOperand* Int8::operator+( const IOperand &rhs) const{
    IOperand *tmp = new Int8(this->getNb() + rhs.getNb());
    return tmp;
}
