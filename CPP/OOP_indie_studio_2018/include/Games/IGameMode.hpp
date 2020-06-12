/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IGameMode
*/

#ifndef IGAMEMODE_HPP_
#define IGAMEMODE_HPP_

#include <string>
#include <iostream>
#include <map>
#include "../irrlicht/irrlicht.h"
#include "../States.hpp"
#include "../Player/PlayerNode.hpp"
#include "../Sfx.hpp"
#include "../EventReceiver.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class IGameMode {
public:
    // IGameMode(states::gameType type);
    virtual ~IGameMode() = default;
    virtual void    setReceiver(EventReceiver *receiver) = 0;
    virtual void    setDevice(IrrlichtDevice *device) = 0;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    virtual void    setPlaylist(std::map<std::string, Sfx*> playlist) = 0;
    #endif
    virtual void    setUp() = 0;
    virtual void    showPlayerStats(APlayerNode *player, rect<s32> pos) = 0;
    virtual void    run() = 0;

protected:
private:
};

#endif /* !IGAMEMODE_HPP_ */
