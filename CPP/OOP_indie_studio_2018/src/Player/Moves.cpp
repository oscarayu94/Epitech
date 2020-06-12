/*
** EPITECH PROJECT, 2019
** moves
** File description:
** moves
*/

#include "../../include/Player/Moves.hpp"

Moves::Moves(IAnimatedMeshSceneNode *node, EventReceiver *reciever, ISceneManager  *manager, states::playerType type)
    :   _node(node), _receiver(reciever), _manager(manager), _prev_key(KEY_KEY_S), _y(10), _x(0), _type(type)
{}

Moves::~Moves()
{}

bool    Moves::resetIfCollide(vector3df current)
{
    array<ISceneNode*> arr;
    //It's a box
    _manager->getSceneNodesFromType(ESNT_CUBE, arr);
    for (int i = 0; i != arr.size(); i++)
        if (arr[i]->getID() == 1 || arr[i]->getID() == 0)
            if (FindCollision::collision(_node, arr[i]) == true) {
                _node->setPosition(current);
                return false;
            }
    //It's fire
    // _manager->getSceneNodesFromType(ESNT_PARTICLE_SYSTEM, arr);
    // for (int i = 0; i != arr.size(); i++)
        // if (FindCollision::collision(_node, arr[i])) {
            // _node->setPosition(current);
            // return false;
        // }
    return true;
}
 
bool    Moves::moveTo(EKEY_CODE key, float vertical, float horizontal)
{
    vector3df current = _node->getPosition();
    if (strcmp(_node->getName(), "PlayerTwo") == 0)
        std::cout << ":" << _node->getName() << ":x:" << current.X << ",y:" << current.Y << ",z:" << current.Z << ",vertical" <<  vertical << ",horiz" << horizontal << "\n" ;
    _node->setPosition(vector3df(current.X + vertical, 0, current.Z + horizontal));
    if (resetIfCollide(current) == true) {
        _prev_key = key;
        _x = horizontal;
        _y = vertical;
        return true;
    }
    return false;
}