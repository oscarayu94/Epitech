/*
** EPITECH PROJECT, 2019
** ainode
** File description:
** ainode by all
*/

#include "../../include/Player/AINode.hpp"

AINode::AINode(IrrlichtDevice *device, vector3df pos, states::playerType type, irr::io::path path)
{
    _device = device;
    _type = type;
    _healthPoints = 1;
    _bombNum = 1;
    _BombPower = 1;
    isBombPlaced = false;
    _manager = _device->getSceneManager();
    _driver = _device->getVideoDriver();
    _node = _manager->addAnimatedMeshSceneNode(_manager->getMesh(path), 0, 10);
    if (!_node)
        exit(84);
    _node->setID(10);
    _node->setMaterialFlag(EMF_LIGHTING, false);
    _node->setPosition(pos);
    _node->setScale(vector3df(2.f, 2.f, 2.f));
}

void    AINode::executeInstructions()
{
    if (_count > 1000000)
        _count = 1;
    srand(time(0) * _count); 
    _count++;
    if (_node->isVisible()) {
        move();
        srand(time(0) * _count); 
        damage();
        setBomb();
    }
}

void    AINode::move()
{
    int random_val;
    
    if (strcmp(_node->getName(), "PlayerTwo") == 0)
        std::cout << "\nbeff prevkey\n";
    random_val = rand() % 4;  
    _count = _count + random_val;
    if(rand() % 3 == 0 &&  _moves->moveTo(_moves->getPrevKey(), _moves->getY(), _moves->getX()) == false) {
        switch(random_val) {
            case 0:
                _moves->moveTo(KEY_KEY_S, 10, 0);
                break;
            case 1:
                _moves->moveTo(KEY_KEY_D, 0, 10);
                break;
            case 2: 
                _moves->moveTo(KEY_KEY_W, -10, 0);
                break;
            default:
                _moves->moveTo(KEY_KEY_A, 0, -10);
        }
    }   
}

void    AINode::setReceiver(EventReceiver *receiver)
{}

void    AINode::printUpdatedPosition(vector3df current)
{}


void    AINode::setBomb()
{
    int random_val;
    random_val = rand() % 50;  
    if (random_val == 0) {
        vector3df playerpos = _node->getPosition();
        playerpos.Z -= -10;
        _bombs.push_back(new BombNode(_device, playerpos, _BombPower));
    }
}

void    AINode::damage() 
{
    if (_node->isVisible()) {
        array<ISceneNode*>  arr;
        _manager->getSceneNodesFromType(ESNT_PARTICLE_SYSTEM, arr);
        for (int i = 0; i != arr.size(); i++) {
            if (FindCollision::collision(_node, arr[i])) {
                setHealthPoints(-1);
                break;
            }
        }
    }    
}

AINode::~AINode()
{}
