/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CubeNode
*/

#include "../include/CubeNode.hpp"

CubeNode::CubeNode(IrrlichtDevice *device, vector3df pos, const io::path path, s32 id)
    :   _manager(device->getSceneManager()), _driver(device->getVideoDriver())
{
    _node = _manager->addCubeSceneNode(10.0f, 0, id);
    if (!_node)
        exit(84);
    _node->setPosition(pos);
    if (strcmp(path.c_str(), "") != 0)
        _node->setMaterialTexture(0, _driver->getTexture(path));
    _node->setMaterialFlag(EMF_LIGHTING, false);
    if (id == 1) {
        _random = rand() % 10;
        PowerUpNode *powerUp = new PowerUpNode(device, _node, _random);
    }
}

CubeNode::~CubeNode()
{
}
