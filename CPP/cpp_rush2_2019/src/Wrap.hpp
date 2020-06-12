/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** wrap
*/

#ifndef WRAP_HPP
#define WRAP_HPP

#include "Object.hpp"

class Wrap: public Object {
public:
    Wrap(void);
    Object *openMe(void);
    void closeMe(void);
    bool isOpen(void) const;
    virtual bool wrapMeThat(Object *toWrap) = 0;
    bool hasContent(void) const;
protected:
    Object *_content;
    bool _isOpen;
};

#endif
