/*
** EPITECH PROJECT, 2019
** AiNode
** File description:
** AiNode
*/

#ifndef AINODE_HPP_
#define AINODE_HPP_

#include "../irrlicht/irrlicht.h"
#include "../States.hpp"
#include "../EventReceiver.hpp"
#include "../BombNode.hpp"
#include "../FindCollision.hpp"
#include "Moves.hpp"
#include <vector>
#include "APlayerNode.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


class AINode : public APlayerNode{
	public:
    	AINode(IrrlichtDevice *device, vector3df pos, states::playerType type = states::COM, irr::io::path path = "../assets/bomberman.3ds");
		~AINode();
		void                    move();
        void                    setReceiver(EventReceiver *receiver);
        void                    printUpdatedPosition(vector3df current) ;
        void                    setBomb();
        void                    damage();
		void                    executeInstructions();

	protected:
	private:
		int _count;
};

#endif /* !AINODE_HPP_ */
