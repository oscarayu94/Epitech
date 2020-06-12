/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** BattleRoyale
*/

#include "../../include/Games/BattleRoyale.hpp"

BattleRoyale::BattleRoyale(std::vector<std::string> map_generator)
    : AGameMode(states::BATTLEROYALE)
{
    _player = NULL;
    _playertwo = NULL;
    _playerthree = NULL;
    _playerfour = NULL;
    hasChoose = false;
    button1 = NULL;
    button2 = NULL;
    _map_array = map_generator;
}

bool    BattleRoyale::playersSelection()
{
    if (hasChoose == false) {
        button1 = _device->getGUIEnvironment()->addButton(rect<s32>(600, 280, 690, 280 + 32), 0, 200, L"One Player Only");
        button2 = _device->getGUIEnvironment()->addButton(rect<s32>(600, 330, 690, 330 + 32), 0, 201, L"Two Players");
        if (_receiver->getSelectedChoice() == 200) {
            _player = setPlayer(states::PLAYERONE,  getPlayerPos(states::PLAYERONE), "../assets/bomberman.3ds", "PlayerOne");
            _playertwo = setPlayer(states::COM, getPlayerPos(2), "../assets/bomberman_pink.3ds", "PlayerTwo");
            _device->getGUIEnvironment()->clear();
            hasChoose = true;
        }
        else if (_receiver->getSelectedChoice() == 201) {
            _player = setPlayer(states::PLAYERONE,  getPlayerPos(1), "../assets/bomberman.3ds", "PlayerOne");
            _playertwo = setPlayer(states::PLAYERTWO, getPlayerPos(2), "../assets/bomberman_yllw.3ds", "PlayerTwo");
            _device->getGUIEnvironment()->clear();
            hasChoose = true;
        }
        if (_playerthree == NULL)
            _playerthree = setPlayer(states::COM, getPlayerPos(3), "../assets/bomberman_green.3ds", "PlayerThree");
        if (_playerfour == NULL)
            _playerfour = setPlayer(states::COM, getPlayerPos(4), "../assets/bomberman_trqs.3ds", "PlayerFour");
        return false;
    }    
    return true;
}

void    BattleRoyale::run()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    playMusic("battle_royale");
    #endif
    if (playersSelection() == true) {
        _player->executeInstructions();
        _playertwo->executeInstructions();
        _playerthree->executeInstructions();
        _playerfour->executeInstructions();
        showPlayerStats(_player, rect<s32>(10, 10, 160, 160));
        showPlayerStats(_playerthree, rect<s32>(10, 550, 160, 700));
        showPlayerStats(_playertwo, rect<s32>(1110, 10, 1260, 160));
        showPlayerStats(_playerfour, rect<s32>(1110, 550, 1260, 700));
        checkGameOver("battle_royale");
    }
}

