/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** ExplosionAnimator
*/

#ifndef EXPLOSIONANIMATOR_HPP_
#define EXPLOSIONANIMATOR_HPP_

#include "irrlicht/irrlicht.h"
#include <iostream>
#include <vector>
#include "Sfx.hpp"
#include "FindCollision.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class ExplosionAnimator : public ISceneNodeAnimator {
public:
    ExplosionAnimator(u32 timeToScale, IrrlichtDevice *device, ISceneNode *bomb, int bombPower);
    virtual ~ExplosionAnimator();
    virtual void                    animateNode(scene::ISceneNode *node, u32 timeMs);
	virtual ISceneNodeAnimator      *createClone(ISceneNode* node, ISceneManager* newManager = 0) { return this; }
    ISceneNode                      *explosionNode(vector3df pos);
    void                            explosionCross(ISceneNode *node, int size = 1);
    void                            eraseCube(ISceneNode *node);

protected:
private:
    IrrlichtDevice              *_device;
    u32                         _startTime;
    u32                         _timeToScale;
    bool                        crossStarted;
    ISceneNode                  *_bomb;
    std::vector<ISceneNode*>    _explosionCross;
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    Sfx                         *_sfx;
    #endif
    int                         _bombPower;

};

#endif /* !EXPLOSIONANIMATOR_HPP_ */
