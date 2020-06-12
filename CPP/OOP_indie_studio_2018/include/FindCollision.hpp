/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** FindCollision
*/

#ifndef FINDCOLLISION_HPP_
#define FINDCOLLISION_HPP_

#include "irrlicht/irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class FindCollision {
public:
    static bool collision(ISceneNode *one, ISceneNode *two);

protected:
private:
    FindCollision();
    ~FindCollision();
    static FindCollision    *_instance;
};

#endif /* !FINDCOLLISION_HPP_ */
