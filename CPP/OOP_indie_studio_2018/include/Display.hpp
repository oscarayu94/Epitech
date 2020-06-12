/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include "irrlicht/irrlicht.h"
#include "../include/EventReceiver.hpp"
#include "../include/States.hpp"
#include "../include/CubeNode.hpp"
#include "../include/Player/PlayerNode.hpp"
#include "../include/MapGenerator.hpp"
#include "../include/Games/IGameMode.hpp"
#include "../include/Games/AGameMode.hpp"
#include "../include/Games/BattleRoyale.hpp"
#include "../include/Games/TwoVsTwo.hpp"
#include "../include/Games/Spectator.hpp"
#include "../include/Sfx.hpp"
#include "../include/Intro.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Display {
public:

    Display();
    ~Display();
    void            setTitle(std::string title);
    void            run();
    void            setFontStyle(const irr::io::path path);
    void            initMainMenuAssets();
    void            runIntro();
    void            runMainMenu();
    void            runGameMode();
    void            runSelectMode();
    void            runGameOver();
    void            initDriver();
    void            initSceneManager();
    void            initGUIEnvironment();
    void            loadGameMap();
    void            drawAll(SColor color);
    void            initPlaylist();
    void            goBackTo(states::scenario scene);

protected:
private:
    IrrlichtDevice              *_device;
    IVideoDriver                *_driver;
    ISceneManager               *_sceneManager;
    IGUIEnvironment             *_guiEnv;
    states::scenario            _scenario;
    EventReceiver               *_receiver;
    std::vector<CubeNode*>      _map;
    AGameMode                   *_game;
    Intro                       *_intro;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    std::map<std::string, Sfx*> _playlist;
    #endif
    //Array of map
    std::vector<std::string>    _map_array;
    //know if comes from load gmae
    bool                        _is_load_game;
    ISceneNode                  *_winner;

};

#endif /* !DISPLAY_HPP_ */