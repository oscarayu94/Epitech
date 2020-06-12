/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** EventReceiver
*/

#ifndef EVENTRECEIVER_HPP_
#define EVENTRECEIVER_HPP_

#include <iostream>
#include "../include/irrlicht/irrlicht.h"
#include "States.hpp"
#include "Sfx.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class EventReceiver : public IEventReceiver {
public:
    EventReceiver(IrrlichtDevice *device, bool *is_load_game);
    void                getKeyInputEvent(const SEvent &event);
    virtual bool        OnEvent(const SEvent &event);
    states::scenario    getCurrentScenario() { return _scene; }
    states::gameType    getSelectedGame() { return _game; }
    void                setGame(states::gameType    game) { _game = game; }
    int                 getSelectedChoice() { return butttonNum; }
    bool                buttonCliked(const SEvent &event, s32 id);
    bool                mainMenuEvent(s32 id);
    virtual bool        IsKeyDown(EKEY_CODE keycode) const { return _keyIsDown[keycode]; }
    void                setScenario(states::scenario scene) { _scene = scene; }

protected:
private:
    IrrlichtDevice      *_device;
    int                 butttonNum;
    states::scenario    _scene;
    states::gameType    _game;
    bool                _keyIsDown[KEY_KEY_CODES_COUNT];
    bool                isKeyPressed;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    Sfx                 *_sfx;
    #endif
    //know if is load game
    bool                *_is_load_game;
};


#endif /* !EVENTRECEIVER_HPP_ */
