/*
** EPITECH PROJECT, 2019
** AplayerNode
** File description:
** APlayerNode
*/

#ifndef APLAYERNODE_HPP_
#define APLAYERNODE_HPP_

#include "../irrlicht/irrlicht.h"
#include "../States.hpp"
#include "../EventReceiver.hpp"
#include "../BombNode.hpp"
#include "../FindCollision.hpp"
#include "Moves.hpp"
#include <vector>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class APlayerNode {
public:
    APlayerNode();
    ~APlayerNode();
    vector3df           getPosition() { return _node->getPosition(); }
    ISceneNode          *getSceneNode() { return _node; }
    ISceneNodeAnimator  *getAnimatorNode() { return _anim; }
    states::playerType  getPlayerType() { return _type; }
    void                setHealthPoints(int health) { _healthPoints = health; }
    int                 getHealthPoints() { return _healthPoints; }
    int                 getBombNum() { return _bombNum; }
    int                 getBombPower() { return _BombPower; }
    void                setName(c8 *name) { _node->setName(name); }
    bool                isPlayerDead() { return _node->isVisible(); }
    void                setPosition(vector3df pos) { _node->setPosition(pos); }
    void                createMoves();

    virtual void        executeInstructions() = 0;
    virtual void        move() = 0;
    virtual void        setReceiver(EventReceiver *receiver) = 0;
    virtual void        printUpdatedPosition(vector3df current) = 0;
    virtual void        setBomb() = 0;
    virtual void        damage() = 0;

protected:
    IrrlichtDevice          *_device;
    states::playerType      _type;
    IAnimatedMeshSceneNode  *_node;
    ISceneManager           *_manager;
    IVideoDriver            *_driver;
    EventReceiver           *_receiver;
    ISceneNodeAnimator      *_anim;
    Moves                   *_moves;
    int                     _healthPoints;
    int                     _bombNum;
    int                     _BombPower;
    int                     _maxBombPower;
    std::vector<BombNode*>  _bombs;
    bool                    isBombPlaced;
    int                     bombTimer;

    bool                    hasMoved;
    int                     _speed;
    int                     _currentSpeed;
    int                     _maxSpeed;

private:

};

#endif /* !APLAYERNODE_HPP_ */
