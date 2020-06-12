/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CubeNode
*/

#ifndef CUBENODE_HPP_
#define CUBENODE_HPP_

#include "irrlicht/irrlicht.h"
#include <string>
#include <iostream>
#include "PowerUpNode.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class CubeNode {
public:
    CubeNode(IrrlichtDevice *device, vector3df pos = vector3df(0, 0, 0), const io::path path = "", s32 id = -1);
    ~CubeNode();
    vector3df   getPosition() { return _node->getPosition(); }
    ISceneNode  *getSceneNode() { return _node; }

protected:
private:
    IMeshSceneNode  *_node;
    ISceneManager   *_manager;
    IVideoDriver    *_driver;
    int             _random;

};

#endif /* !CUBENODE_HPP_ */
