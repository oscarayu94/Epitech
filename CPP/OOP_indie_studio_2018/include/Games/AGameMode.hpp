/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AGameMode
*/

#ifndef AGAMEMODE_HPP_
#define AGAMEMODE_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "IGameMode.hpp"
#include "LoadMap.hpp"
#include "../../include/EventReceiver.hpp"
#include "../CubeNode.hpp"
#include "../Player/PlayerNode.hpp"
#include "../Player/AINode.hpp"

#include "../MapGenerator.hpp"
#include "../Sfx.hpp"

class AGameMode : public IGameMode {
public:
    AGameMode(states::gameType type);
    void            setReceiver(EventReceiver *receiver);
    void            setDevice(IrrlichtDevice *device);
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    void            setPlaylist(std::map<std::string, Sfx*> playlist);
    void            playMusic(std::string musicname);
    void            stopMusic(std::string musicname);
    #endif
    void            setUp();
    void            loadGameMap();
    void            saveGame();
    void            run() {}
    void            setSky();
    void            setCamera();
    void            updateMapWithNewPos();
    APlayerNode      *setPlayer(states::playerType type, vector3df position, irr::io::path path, std::string name);
    void            showPlayerStats(APlayerNode *player, rect<s32> pos);
    vector3df       getPlayerPos(int type);
    void            checkGameOver(std::string musicToStop);
    void            setWinner(ISceneNode *player) { _winner = player; }
    ISceneNode      *getWinner() { return _winner; }
    std::string     getWinnerName(ISceneNode *player) {
        std::string s(player->getName());
        return s;
    }

protected:
    IrrlichtDevice          *_device;
    EventReceiver           *_receiver;
    APlayerNode             *_player;
    APlayerNode             *_playertwo;
    APlayerNode             *_playerthree;
    APlayerNode             *_playerfour;
    ICameraSceneNode        *_cam;
    std::vector<std::string>    _map_array;
    LoadMap                 load_map;
    //The game name
    std::string             _game_name;
    bool                    isGameOver;

private:
    std::vector<CubeNode*>      _map;
    bool                        createdSky;
    bool                        isCameraSet;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    std::map<std::string, Sfx*> _playlist;
    #endif
    states::gameType            _type;
    ISceneNode                 *_winner;

};

#endif /* !AGAMEMODE_HPP_ */
