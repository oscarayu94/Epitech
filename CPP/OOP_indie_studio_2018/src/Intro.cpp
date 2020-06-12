/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Intro
*/

#include "../include/Intro.hpp"

Intro::Intro(IrrlichtDevice *device, EventReceiver *receiver)
{
    _device = device;
    _receiver = receiver;
    _env = _device->getGUIEnvironment();
    _driver = _device->getVideoDriver();
    _teamname = _env->addStaticText(L"A DunJohny's game", rect<s32>(400, 200, 800, 270), false);
    _presents = _env->addStaticText(L"Presents...", rect<s32>(400, 280, 800, 350), false);
    _titlelogo = _env->addImage(_driver->getTexture("../assets/logo.png"), position2d<int>(0, 50));
    _teamname->setOverrideColor(SColor(_teamname->getOverrideColor().getAlpha() + 2, 0, 0, 0));
    _presents->setOverrideColor(SColor(_presents->getOverrideColor().getAlpha() + 2, 0, 0, 0));
    _presents->setVisible(false);
    _titlelogo->setVisible(false);
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    _sfx = NULL;
    if (_sfx == NULL)
        _sfx = new Sfx("menu_intro_3", false);
    _sfx->setVolume(45);
    _sfx->play();
    #endif
}

void    Intro::play()
{
    if (_teamname->getOverrideColor().getAlpha() != 0)
        _teamname->setOverrideColor(SColor(_teamname->getOverrideColor().getAlpha() - 1, 0, 0 , 0));
    else if (_teamname->getOverrideColor().getAlpha() == 0) {
        _teamname->setVisible(false);
        _presents->setVisible(true);
        if (_presents->getOverrideColor().getAlpha() != 0)
            _presents->setOverrideColor(SColor(_presents->getOverrideColor().getAlpha() - 1, 0, 0 , 0));
        else if (_presents->getOverrideColor().getAlpha() == 0) {
            _presents->setVisible(false);
            _titlelogo->setVisible(true);
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            _env->clear();
            _receiver->setScenario(states::MAINMENU);
            delete this;
            #else
            if (_sfx->getStatus() == 0) {
                _env->clear();
                _receiver->setScenario(states::MAINMENU);
                delete this;
            }
            #endif
        }
    }
}

Intro::~Intro()
{
}
