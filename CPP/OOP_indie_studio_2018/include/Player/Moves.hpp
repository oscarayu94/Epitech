/*
** EPITECH PROJECT, 2019
** Moves
** File description:
** Moves
*/

#ifndef moves
#define moves

#include "../irrlicht/irrlicht.h"
#include "../States.hpp"
#include "../EventReceiver.hpp"
#include "../BombNode.hpp"
#include "../FindCollision.hpp"
#include "Moves.hpp"
#include <vector>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Moves {
public:
    Moves(IAnimatedMeshSceneNode *, EventReceiver *, ISceneManager *, states::playerType type);
    ~Moves();
    bool        resetIfCollide(vector3df current);
    bool        moveTo(EKEY_CODE key, float vertical, float horizontal);
    EKEY_CODE   getPrevKey() { return _prev_key; };
    int         getX() { return _x; };
    int         getY() { return _y; };  
   
protected:
private:
    IAnimatedMeshSceneNode  *_node;
    EventReceiver           *_receiver; 
    ISceneManager           *_manager;
    //Values
    EKEY_CODE               _prev_key;
    int                     _x;
    int                     _y;
    states::playerType      _type;

};

#endif /* !d */
