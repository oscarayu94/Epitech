/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** BattleRoyale
*/

#ifndef BATTLEROYALE_HPP_
#define BATTLEROYALE_HPP_

#include "AGameMode.hpp"

class BattleRoyale : public AGameMode {
public:
    BattleRoyale(std::vector<std::string> );
    void    run();
    bool    playersSelection();

protected:
private:
    bool        hasChoose;
    IGUIButton  *button1;
    IGUIButton  *button2;
};

#endif /* !BATTLEROYALE_HPP_ */
