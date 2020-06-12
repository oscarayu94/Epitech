/*
** EPITECH PROJECT, 2019
** load map by oriol
** File description:
** load map by oriol
*/

#ifndef LOADMAP_HPP_
#define LOADMAP_HPP_

#include <string.h>
#include <iostream>
#include <limits.h>
#include <iostream>
#include <list>
#include <iomanip>
#include <string>
#include <iomanip>
#include <unordered_map>
// #include <unistd.h>
#include <cstddef>
#include <array>
#include <map>
#include <vector>
#include <algorithm>
#include "../irrlicht/irrlicht.h"
#include "../States.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class LoadMap {
public:
	LoadMap();
	~LoadMap();
	void 		saveGame( std::vector<std::string> , IrrlichtDevice * ,states::gameType);
	void 		updateMapWithNewPos();
	void 		updateMapWithNewPlayerPos(array<ISceneNode*> arr);
	void 		updateMapWithNewDestructiveWalls(array<ISceneNode*> arr);
	static		std::vector<std::string> getMap();
	static int	getGameId();

protected:
private:
	IrrlichtDevice          *_device;
	std::vector<std::string> _map_array;
};

#endif /* !LOADMAP_HPP_ */
