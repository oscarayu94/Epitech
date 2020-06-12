/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** States
*/

#ifndef STATES_HPP_
#define STATES_HPP_

namespace states {
    enum scenario {
        INTRO = 10,
        MAINMENU,
        GAMESELECT,
        GAMEMODE,
        GAMEOVER
    };
    enum buttonEvent {
        QUITGAME = 1,
        NEWGAME,
        LOADGAME
    };
    enum gameType {
        BATTLEROYALE = 101,
        TWOVSTWO,
        SPECTATOR
    };
    enum playerType {
        PLAYERONE = 1,
        PLAYERTWO,
        COM
    };
}


#endif /* !STATES_HPP_ */
