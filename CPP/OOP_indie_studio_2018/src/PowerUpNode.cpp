/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PowerUpNode
*/

#include "../include/PowerUpNode.hpp"

PowerUpNode::PowerUpNode(IrrlichtDevice *device, ISceneNode *parent, int rndNum)
    :   _device(device), _manager(device->getSceneManager()), _driver(device->getVideoDriver())
{
    switch (rndNum) {
    case 1:
        createPowerUpNode(parent, "../assets/powerups/bombs.jpg", "bombs");
        break;
    case 2:
        createPowerUpNode(parent, "../assets/powerups/fire.jpg", "fire");
        break;
    case 3:
        createPowerUpNode(parent, "../assets/powerups/ghost.jpg", "ghost");
        break;
    case 4:
        createPowerUpNode(parent, "../assets/powerups/speed.jpg", "speed");
        break;
    default:
        delete this;
        break;
    }
}

void    PowerUpNode::createPowerUpNode(ISceneNode *parent, irr::io::path path, stringc name)
{
    _node = _manager->addCubeSceneNode(5.0f, 0, 3);
    _node->setPosition(parent->getPosition());
    _node->setMaterialTexture(0, _driver->getTexture(path));
    _node->setMaterialFlag(EMF_LIGHTING, false);
    _node->setName(name);
    _node->addAnimator(_manager->createRotationAnimator(vector3df(0, 0.5, 0)));
}

PowerUpNode::~PowerUpNode()
{
}
