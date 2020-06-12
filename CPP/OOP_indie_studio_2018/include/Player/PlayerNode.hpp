/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PlayerNode
*/

#ifndef PLAYERNODE_HPP_
#define PLAYERNODE_HPP_

#include "../irrlicht/irrlicht.h"
#include "../States.hpp"
#include "../EventReceiver.hpp"
#include "../BombNode.hpp"
#include "../FindCollision.hpp"
#include "Moves.hpp"
#include <vector>
#include "APlayerNode.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class PlayerNode : public APlayerNode {
public:
    PlayerNode(IrrlichtDevice *device, vector3df pos, states::playerType type = states::COM, irr::io::path path = "../assets/bomberman.3ds");
    ~PlayerNode();
    void    move();
    void    setReceiver(EventReceiver *receiver);
    void    printUpdatedPosition(vector3df current);
    void    setBomb();
    void    damage();
    void    executeInstructions();
    void    callMoveTo(EKEY_CODE key, float vertical, float horizontal);
    void    powerUp();
    void    limiters();

protected:
private:

};

#endif /* !PLAYERNODE_HPP_ */
