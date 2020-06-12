/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** paper
*/

#ifndef GIFTPAPER_HPP
#define GIFTPAPER_HPP

#include "Wrap.hpp"

class GiftPaper: public Wrap {
public:
    GiftPaper(void);
    bool wrapMeThat(Object *toWrap) override;
};

#endif
