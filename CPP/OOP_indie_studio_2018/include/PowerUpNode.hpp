/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PowerUpNode
*/

#ifndef POWERUPNODE_HPP_
#define POWERUPNODE_HPP_

#include "irrlicht/irrlicht.h"
#include <iostream>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class PowerUpNode {
public:
    PowerUpNode(IrrlichtDevice *device, ISceneNode *node, int rndNum);
    ~PowerUpNode();
    void    createPowerUpNode(ISceneNode *parent, irr::io::path path, stringc name);

protected:
private:
    IrrlichtDevice  *_device;
    ISceneManager   *_manager;
    IVideoDriver    *_driver;
    IMeshSceneNode  *_node;
};

#endif /* !POWERUPNODE_HPP_ */
