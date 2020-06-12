/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** BombNode
*/

#include "../include/BombNode.hpp"

BombNode::BombNode(IrrlichtDevice *device, vector3df pos, int bombPower)
{
    _device = device;
    timer = _device->getTimer()->getTime();
    hasExploded = false;
    _manager = _device->getSceneManager();
    _driver = _device->getVideoDriver();
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    _sfx = new Sfx("put", false);
    _sfx->play();
    #endif
    _node = _manager->addAnimatedMeshSceneNode(_manager->getMesh("../assets/bomb/bomb.obj"), 0, -10, pos, vector3df(0, 0, 0), vector3df(5.f, 5.f, 5.f));
    _node->setMaterialFlag(EMF_LIGHTING, false);
    _anim = new ExplosionAnimator(2500, _device, _node, bombPower);
    if (_anim) {
        _node->addAnimator((ISceneNodeAnimator*)_anim);
        _anim->drop();
    }
}
