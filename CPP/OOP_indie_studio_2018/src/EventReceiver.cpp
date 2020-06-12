/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** EventReceiver
*/

#include "../include/EventReceiver.hpp"

EventReceiver::EventReceiver(IrrlichtDevice *device, bool *is_load_game)
    : _device(device) {
    for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
        _keyIsDown[i] = false;
    _scene = states::INTRO;
    isKeyPressed = false;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    _sfx = NULL;
    #endif
    _is_load_game = is_load_game;
}

void    EventReceiver::getKeyInputEvent(const SEvent &event)
{
    if (event.EventType == EET_KEY_INPUT_EVENT) {
        _keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
}

bool    EventReceiver::mainMenuEvent(s32 id)
{
    if (id == states::QUITGAME) {
        _device->closeDevice();
        return true;
    }
    else if (id == states::NEWGAME) {
        _device->getGUIEnvironment()->clear();
        _device->getSceneManager()->clear();
        _scene = states::GAMESELECT;
        return true;
    }
    else if (id == states::LOADGAME) {
        _device->getGUIEnvironment()->clear();
        _device->getSceneManager()->clear();
        *_is_load_game = true;
        _scene = states::GAMEMODE;
        std::cout << "In progress, please come back later" << std::endl;
        return true;
    }    
}

bool    EventReceiver::buttonCliked(const SEvent &event, s32 id)
{
    if (event.GUIEvent.EventType == EGET_BUTTON_CLICKED) {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #else
        _sfx = new Sfx("accept", false);
        _sfx->play();
        #endif
        mainMenuEvent(id);
        if (_scene == states::GAMEMODE) {
            if (id == 200 || id == 201) {
                butttonNum = id;
            }
        }
        switch (id) {
            case states::BATTLEROYALE:
            case states::TWOVSTWO:
            case states::SPECTATOR:
            _device->getGUIEnvironment()->clear();
            _device->getSceneManager()->clear();
            _game = static_cast<states::gameType>(id);
            _scene = states::GAMEMODE;
            return true;
        }
        return false;
    }
}

bool    EventReceiver::OnEvent(const SEvent &event)
{
    getKeyInputEvent(event);
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        buttonCliked(event, id);
    }
    return false;
}