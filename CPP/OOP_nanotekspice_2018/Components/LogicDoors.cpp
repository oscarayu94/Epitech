/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** LogicDoors
*/

#include "LogicDoors.hpp"

bool    AND::compute(bool a, bool b)
{
    if (a == false && b == false)
        return true;
    if (a == false && b == true)
        return false;
    if (a == true && b == false)
        return false;
    return true;
}

bool    NAND::compute(bool a, bool b)
{
    if (a == false && b == false)
        return true;    
    if (a == false && b == true)
        return true;
    if (a == true && b == false)
        return true;
    return false;
}

bool    NOR::compute(bool a, bool b)
{
    if (a == false && b == false)
        return true;
    if (a == false && b == true)
        return false;
    if (a == true && b == false)
        return false;
    return false;
}

bool    OR::compute(bool a, bool b)
{
    if (a == false && b == false)
        return false;
    if (a == false && b == true)
        return true;
    if (a == true && b == false)
        return true;
    return true;
}

bool    XOR::compute(bool a, bool b)
{
    if (a == false && b == false)
        return false;
    if (a == false && b == true)
        return true;
    if (a == true && b == false)
        return true;
    return false;    
}