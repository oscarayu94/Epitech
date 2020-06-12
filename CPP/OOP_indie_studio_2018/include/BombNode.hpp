/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** BombNode
*/

#ifndef BOMBNODE_HPP_
#define BOMBNODE_HPP_

#include "irrlicht/irrlicht.h"
#include "States.hpp"
#include "EventReceiver.hpp"
#include "ExplosionAnimator.hpp"
#include "Sfx.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class BombNode {
public:
    BombNode(IrrlichtDevice *device, vector3df pos, int bombPower);
    IAnimatedMeshSceneNode  *getAnimatedNode() { return _node; }

protected:
private:
    IrrlichtDevice          *_device;
    IAnimatedMeshSceneNode  *_node;
    ISceneManager           *_manager;
    IVideoDriver            *_driver;
    ISceneNodeAnimator      *_anim;
    s32                     timer;
    bool                    hasExploded;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    Sfx                     *_sfx;
    #endif
    // int                     _bombPower;
    
};

#endif /* !BOMBNODE_HPP_ */
