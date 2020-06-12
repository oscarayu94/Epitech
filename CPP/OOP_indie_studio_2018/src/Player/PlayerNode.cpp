/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PlayerNode
*/

#include "../../include/Player/PlayerNode.hpp"

PlayerNode::PlayerNode(IrrlichtDevice *device, vector3df pos, states::playerType type, irr::io::path path)
{
    _device = device;
    _type = type;
    _healthPoints = 1;
    _bombNum = 1;
    _BombPower = 1;
    _maxBombPower = 3;
    isBombPlaced = false;
    bombTimer = 100;
    hasMoved = false;
    _speed = 12;
    _currentSpeed = _speed;
    _maxSpeed = 4;
    _manager = _device->getSceneManager();
    _driver = _device->getVideoDriver();
    _node = _manager->addAnimatedMeshSceneNode(_manager->getMesh(path), 0, 10);
    if (!_node)
        exit(84);
    _node->setID(10);
    _node->setMaterialFlag(EMF_LIGHTING, false);
    _node->setPosition(pos);
    _node->setScale(vector3df(2.f, 2.f, 2.f));
}

void    PlayerNode::executeInstructions()
{
    move();
    damage();
    powerUp();
    limiters();
}

void    PlayerNode::limiters()
{
    if (isBombPlaced) {
        bombTimer--;
        if (bombTimer == 0)
            isBombPlaced = false;
    }
    if (hasMoved) {
        _speed--;
        if (_speed == 0)
            hasMoved = false;
    }
}

void    PlayerNode::powerUp()
{
    array<ISceneNode*>  arr;

    _manager->getSceneNodesFromType(ESNT_CUBE, arr);
    for (int i = 0; i != arr.size(); i++) {
        if (arr[i]->getID() == 3) {
            if (FindCollision::collision(_node, arr[i]) == true) {
                std::string name(arr[i]->getName());
                if (name == "fire" && _BombPower != _maxBombPower) {
                    arr[i]->setID(-1);
                    arr[i]->setVisible(false);
                    _BombPower++;
                    std::cout << _BombPower << std::endl;
                    break;
                }
                if (name == "speed" && _speed > _maxSpeed) {
                    arr[i]->setID(-1);
                    arr[i]->setVisible(false);
                    _speed -= 2;
                    _currentSpeed = _speed;
                    std::cout << _speed << std::endl;
                    break;
                }
            }
        }
    }
}

void    PlayerNode::setReceiver(EventReceiver *receiver)
{
    _receiver = receiver;
}

void    PlayerNode::printUpdatedPosition(vector3df current)
{
    vector3df   upd = _node->getPosition();

    if (upd.X != current.X || upd.Y != current.Y || upd.Z != current.Z)
        std::cout << "Player " << _type << " has moved to (" << upd.X << "," << upd.Y << "," << upd.Z << ")" << std::endl;
}


void    PlayerNode::damage()
{
    if (_node->isVisible()) {
        array<ISceneNode*>  arr;
        _manager->getSceneNodesFromType(ESNT_PARTICLE_SYSTEM, arr);
        for (int i = 0; i != arr.size(); i++) {
            if (FindCollision::collision(_node, arr[i])) {
                setHealthPoints(-1);
                break;
            }
        }
    }
}

void PlayerNode::callMoveTo(EKEY_CODE key, float vertical, float horizontal)
{
    if (_receiver->IsKeyDown(key) && !hasMoved) {
        _moves->moveTo(key, vertical, horizontal);
        _speed = _currentSpeed;
        hasMoved = true;
    }
}

void    PlayerNode::move()
{
    if (_node->isVisible()) {
        if (_type == states::PLAYERONE) {
            
            callMoveTo(KEY_KEY_S, 10, 0);
            callMoveTo(KEY_KEY_W, -10, 0);
            callMoveTo(KEY_KEY_D, 0, 10);
            callMoveTo(KEY_KEY_A, 0, -10);
        }
        else if (_type == states::PLAYERTWO) {
            callMoveTo(KEY_DOWN, 10, 0);
            callMoveTo(KEY_UP, -10, 0);
            callMoveTo(KEY_RIGHT, 0, 10);
            callMoveTo(KEY_LEFT, 0, -10);
        }
        setBomb();
    }
}

void    PlayerNode::setBomb()
{
    vector3df playerpos = _node->getPosition();
    playerpos.Z -= -10;
    if (_type == states::PLAYERONE && !isBombPlaced) {
        if (_receiver->IsKeyDown(KEY_LSHIFT) || _receiver->IsKeyDown(KEY_KEY_R)) {
            _bombs.push_back(new BombNode(_device, playerpos, _BombPower));
            isBombPlaced = true;
            bombTimer = 100;            
        }
    }
    else if (_type == states::PLAYERTWO && !isBombPlaced) {
        if (_receiver->IsKeyDown(KEY_RSHIFT) || _receiver->IsKeyDown(KEY_RCONTROL)) {
            _bombs.push_back(new BombNode(_device, playerpos, _BombPower));
            isBombPlaced = true;
            bombTimer = 100;
        }
    }
}

PlayerNode::~PlayerNode()
{
}
