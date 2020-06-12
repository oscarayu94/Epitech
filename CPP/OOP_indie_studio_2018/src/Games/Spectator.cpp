/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Spectator
*/

#include "../../include/Games/Spectator.hpp"

Spectator::Spectator(std::vector<std::string> map_generator)
    : AGameMode(states::SPECTATOR)
{
    _player = NULL;
    _playertwo = NULL;
    _playerthree = NULL;
    _playerfour = NULL;
    _isTargetOriginSet = false;
    _arePlayersSet = false;
    _isTargetSelected = false;
    _map_array = map_generator;

}

void    Spectator::helpControls()
{
    std::wstring    str = L"Use W and S keys to move the camera up or down\nA and D to move the camera left or right\nQ and E to zoom in and out";
    std::wstring    str2 = L"Press the num keys from 1 to 4 to follow one of the players\n0 num key to reset the camera";

    IGUIStaticText  *text = _device->getGUIEnvironment()->addStaticText(str.c_str(), rect<s32>(100, 10, 250, 80), true);
    text->setOverrideColor(SColor(255, 255, 255, 255));

    IGUIStaticText  *targetText = _device->getGUIEnvironment()->addStaticText(str2.c_str(), rect<s32>(100, 90, 250, 160), true);
    targetText->setOverrideColor(SColor(255, 255, 255, 255));
}

void	Spectator::targetPlayer(EKEY_CODE key, APlayerNode *player)
{
    if (_receiver->IsKeyDown(key)) {
        vector3df   pos = player->getPosition();
        _cam->setTarget(pos);
        pos.Y += _cam->getPosition().Y;
        pos.X += 1;
        _cam->setPosition(pos);
        _isTargetSelected = true;
    }

}

void    Spectator::followTarget(APlayerNode *player)
{
    if (_isTargetSelected && player != NULL) {
        vector3df   pos = player->getPosition();
        _cam->setTarget(pos);
        pos.Y += _cam->getPosition().Y;
        pos.X += 1;
        _cam->setPosition(pos);
    }
}

void    Spectator::setAiPlayers()
{
    if (!_arePlayersSet) {
        _player = setPlayer(states::COM, vector3df(0, 0, 0), "../assets/bomberman.3ds", "PlayerOne");
        _playertwo = setPlayer(states::COM, vector3df(180, 0, 0), "../assets/bomberman_yllw.3ds", "PlayerTwo");
        _playerthree = setPlayer(states::COM, vector3df(0, 0, 180), "../assets/bomberman_green.3ds", "PlayerThree");
        _playerfour = setPlayer(states::COM, vector3df(180, 0, 180), "../assets/bomberman_trqs.3ds", "PlayerFour");
        _arePlayersSet = true;
    }
}

void    Spectator::moveCamTo(EKEY_CODE key, float x, float y , float z)
{
    vector3df   pos = _cam->getPosition();
    vector3df   tar = _cam->getTarget();
    
    if (_receiver->IsKeyDown(key)) {
        _cam->setPosition(vector3df(pos.X + x, pos.Y + y, pos.Z + z));
        _cam->setTarget(vector3df(tar.X + x, tar.Y + y, tar.Z + z));
        _isTargetSelected = false;
    }
}

void    Spectator::moveCam()
{
    vector3df   pos = _cam->getPosition();
    vector3df   tar = _cam->getTarget();
    moveCamTo(KEY_KEY_W, -1);
    moveCamTo(KEY_KEY_S, 1);
    moveCamTo(KEY_KEY_D, 0, 0, 1);
    moveCamTo(KEY_KEY_A, 0, 0, -1);
    if (_receiver->IsKeyDown(KEY_KEY_Q) && pos.Y < f32(250.0)) {
        _cam->setPosition(vector3df(pos.X, pos.Y + 1, pos.Z));
        _isTargetSelected = false;
    }
    else if (_receiver->IsKeyDown(KEY_KEY_E) && pos.Y > f32(50.0)) {
        _cam->setPosition(vector3df(pos.X, pos.Y - 1, pos.Z));
        _isTargetSelected = false;
    }
    else if (_receiver->IsKeyDown(KEY_KEY_0)) {
        _cam->setPosition(_positionOrigin);
        _cam->setTarget(_targetOrigin);
        _isTargetSelected = false;
    }
    std::cout << "target position X " << tar.X << ", Y " << tar.Y << " , Z " << tar.Z << std::endl;
    std::cout << "Camera position X " << pos.X << ", Y " << pos.Y << " , Z " << pos.Z << std::endl;
}

void    Spectator::run()
{
    setAiPlayers();
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    playMusic("spectator");
    #endif
    if (!_isTargetOriginSet) {
        _targetOrigin = _cam->getTarget();
        _positionOrigin = _cam->getPosition();
        _isTargetOriginSet = true;
    }
    targetPlayer(KEY_KEY_1, _player);
    targetPlayer(KEY_KEY_2, _playertwo);
    targetPlayer(KEY_KEY_3, _playerthree);
    targetPlayer(KEY_KEY_4, _playerfour);
    moveCam();
    _player->executeInstructions();
    _playertwo->executeInstructions();
    _playerthree->executeInstructions();
    _playerfour->executeInstructions();
    helpControls();
}
