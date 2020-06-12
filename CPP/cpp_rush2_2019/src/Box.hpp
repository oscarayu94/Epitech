/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** box
*/

#ifndef BOX_HPP
#define BOX_HPP

#include "Wrap.hpp"

class Box: public Wrap {
public:
    Box(void);
    bool wrapMeThat(Object *toWrap);
};

#endif
