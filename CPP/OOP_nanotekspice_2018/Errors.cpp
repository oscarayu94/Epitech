/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Errors
*/

#include "Errors.hpp"

ComponentTypeUnknown::ComponentTypeUnknown() 
    : Errors("Unknown type for component.\n")
{
    exit(84);
}

ComponentNameUnknown::ComponentNameUnknown()
    : Errors("Unknown name for component.\n")
{
    exit(84);
}

PinNoExist::PinNoExist()
    : Errors("Required pin does not exist/\n")
{
    exit(84);
}

ComponentSameName::ComponentSameName()
    : Errors("Components with same name has been found.\n")
{
    exit(84);
}

NotLinkedOutput::NotLinkedOutput()
    : Errors("Output has not been linked.\n")
{
    exit(84);
}

NotProvidedInput::NotProvidedInput()
    : Errors("No Input provided.\n")
{
    exit(84);
}

UnknownProvidedInput::UnknownProvidedInput()
    : Errors("Unknown Input provided.\n")
{
    exit(84);
}

NoChipsetSection::NoChipsetSection()
    : Errors("No chipset section in this file.\n")
{
    exit(84);
}

NoLinksSection::NoLinksSection()
    : Errors("No links section in this file.\n")
{
    exit(84);
}