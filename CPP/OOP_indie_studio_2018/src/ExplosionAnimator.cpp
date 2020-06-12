/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** ExplosionAnimator
*/

#include "../include/ExplosionAnimator.hpp"

ExplosionAnimator::ExplosionAnimator(u32 timeToScale, IrrlichtDevice *device, ISceneNode *bomb, int bombPower)
    : _device(device), _startTime(0), _timeToScale(timeToScale), crossStarted(false), _bomb(bomb), _bombPower(bombPower)
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    _sfx = NULL;
    #endif
}

ExplosionAnimator::~ExplosionAnimator()
{

}

ISceneNode    *ExplosionAnimator::explosionNode(vector3df pos)
{
    ISceneManager   *manager    = _device->getSceneManager();
    IVideoDriver    *driver = _device->getVideoDriver();
    aabbox3d<f32>   box(-5, 0, -5, 5, 1, 5);
    vector3df       streamDirection(0.0f, 0.06f, 0.0f);
    u32             minParticlePerSecond = 380;
    u32             maxParticlePerSecond = 400;
    SColor          minColor(0, 255, 255, 255);
    SColor          maxColor(0, 255, 255, 255);
    u32             lifetimeMin = 100;
    u32             lifeTimeMax = 500;
    s32             maxAngle = 0;
    dimension2df    minStartSize(5.f, 1.f);
    dimension2df    maxStartSize(10.f, 5.f);

    IParticleSystemSceneNode    *ps = manager->addParticleSystemSceneNode(false);

    IParticleEmitter    *em = ps->createBoxEmitter(box, streamDirection, minParticlePerSecond, maxParticlePerSecond, minColor, maxColor, lifetimeMin, lifeTimeMax, maxAngle, minStartSize, maxStartSize);
    ps->setEmitter(em);
    em->drop();

    IParticleAffector   *paf = ps->createFadeOutParticleAffector();
    ps->addAffector(paf);
    paf->drop();

    ps->setPosition(pos);
    ps->setScale(vector3df(0.5f, 1.f, 1.f));
    ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, driver->getTexture("../assets/fire/fireball.bmp"));
	ps->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
    return ps;
}

void    ExplosionAnimator::eraseCube(ISceneNode *node)
{
    ISceneManager   *manager = _device->getSceneManager();
    array<ISceneNode*>  arr;
    manager->getSceneNodesFromType(ESNT_CUBE, arr);
    for (int i = 0; i != arr.size(); i++) {
        if (arr[i]->getID() == 1) {
            if (FindCollision::collision(node, arr[i]) == true) {
                arr[i]->setID(-1);
                arr[i]->setVisible(false);
            }
        }
    }
}

void    ExplosionAnimator::explosionCross(ISceneNode *node, int size)
{
    vector3df   pos = node->getPosition();
    pos.X += 10;
    if (_explosionCross.empty()) {
        _explosionCross.push_back(explosionNode(pos));
        for (int i = 0; i != size; i++) {
            _explosionCross.push_back(explosionNode(vector3df(pos.X - 10 * (i + 1), 0, pos.Z)));
            _explosionCross.push_back(explosionNode(vector3df(pos.X + 10 * (i + 1), 0, pos.Z)));
            _explosionCross.push_back(explosionNode(vector3df(pos.X, 0, pos.Z - 10 * (i + 1))));
            _explosionCross.push_back(explosionNode(vector3df(pos.X, 0, pos.Z + 10 * (i + 1))));
        }
        for (auto a : _explosionCross)
            eraseCube(a);
    }
}

void    ExplosionAnimator::animateNode(ISceneNode *node, u32 timeMs)
{
    if (_startTime == 0)
        _startTime = timeMs;
    u32 passTime = timeMs - _startTime;
    if (passTime > _timeToScale / 1.5 && !crossStarted) {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #else
        if (_sfx == NULL) {
            _sfx = new Sfx("explode", false);
            _sfx->play();
        }
        #endif
        explosionCross(node, _bombPower);
        crossStarted = true;
    }
    if (passTime > _timeToScale) {
        for (auto a : _explosionCross) {
            a->setID(-10);
            a->remove();
        }
        _explosionCross.clear();
        _bomb->setVisible(false);
        // _bomb->remove();
        return;
    }
    // float progress = float(passTime) / float(_timeToScale);
}