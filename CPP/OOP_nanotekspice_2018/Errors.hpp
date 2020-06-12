/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <exception>

class Errors : public std::exception {
public:
    Errors(std::string const &message) : _message(message) {}
    const char  *what() const throw() { return _message.c_str(); }

protected:
    std::string _message;
};

class ComponentTypeUnknown : public Errors {
public:
    ComponentTypeUnknown();
};

class ComponentNameUnknown : public Errors {
public:
    ComponentNameUnknown();
};

class PinNoExist : public Errors {
public:
    PinNoExist();
};

class ComponentSameName : public Errors {
public:
    ComponentSameName();
};

class NotLinkedOutput : public Errors {
public:
    NotLinkedOutput();
};

class NotProvidedInput : public Errors {
public:
    NotProvidedInput();
};

class UnknownProvidedInput : public Errors {
public:
    UnknownProvidedInput();
};

class NoChipsetSection : public Errors {
public:
    NoChipsetSection();
};

class NoLinksSection : public Errors {
public:
    NoLinksSection();
};

#endif /* !ERRORS_HPP_ */
