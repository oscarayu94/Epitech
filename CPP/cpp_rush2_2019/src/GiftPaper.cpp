/*
** EPITECH PROJECT, 2020
** cpp rush 2
** File description:
** giftpaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(void): Wrap()
{
    _title = "GiftPaper";
}

bool GiftPaper::wrapMeThat(Object *toWrap)
{
    if (_content)
        return (false);
    _content = toWrap;
    std::cout << "tuuuut tuuut tuut\n";
    return (true);
}
