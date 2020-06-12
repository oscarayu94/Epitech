/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Spectator
*/

#ifndef SPECTATOR_HPP_
#define SPECTATOR_HPP_

#include "AGameMode.hpp"

class Spectator : public AGameMode {
public:
    Spectator(std::vector<std::string>);
    void    run();
    void    helpControls();
    void    setAiPlayers();
    void    moveCam();
    void    targetPlayer(EKEY_CODE key, APlayerNode *player);
    void    followTarget(APlayerNode *player = NULL);

protected:
private:
    void        moveCamTo(EKEY_CODE key, float x = 0, float y = 0, float z = 0);
    bool        _isTargetOriginSet;
    bool        _arePlayersSet;
    bool        _isTargetSelected;
    vector3df   _targetOrigin;
    vector3df   _positionOrigin;
};

#endif /* !SPECTATOR_HPP_ */
