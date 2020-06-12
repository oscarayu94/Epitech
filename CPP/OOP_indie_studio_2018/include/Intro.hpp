/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Intro
*/

#ifndef INTRO_HPP_
#define INTRO_HPP_

#include <iostream>
#include "irrlicht/irrlicht.h"
#include "../include/EventReceiver.hpp"
#include "../include/States.hpp"
#include "../include/Sfx.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Intro {
public:
    Intro(IrrlichtDevice *device, EventReceiver *receiver);
    ~Intro();
    void    play();

protected:
private:
    IrrlichtDevice  *_device;
    EventReceiver   *_receiver;
    IGUIEnvironment *_env;
    IVideoDriver    *_driver;
    IGUIStaticText  *_teamname;
    IGUIStaticText  *_presents;
    IGUIStaticText  *_titlegame;
    IGUIImage       *_titlelogo;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    Sfx             *_sfx;
    #endif
};

#endif /* !INTRO_HPP_ */
