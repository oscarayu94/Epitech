/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** FindCollision
*/

#include "../include/FindCollision.hpp"

FindCollision::FindCollision()
{
}

FindCollision::~FindCollision()
{
}

bool    FindCollision::collision(ISceneNode *one, ISceneNode *two)
{
    aabbox3d<f32>   b1 = one->getBoundingBox();
    aabbox3d<f32>   b2 = two->getBoundingBox();

    one->getRelativeTransformation().transformBoxEx(b1);
    two->getRelativeTransformation().transformBoxEx(b2);
    return b1.intersectsWithBox(b2);
}
