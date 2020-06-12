/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MapGenerator
*/

#ifndef MAPGENERATOR_HPP_
#define MAPGENERATOR_HPP_

#include <ctime>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <functional>

class MapGenerator {
public:	
    static std::vector<std::string> generateMap(int);
    static std::string              addCharacters(std::string str, int size, int);
    static std::string              setDestructibleWalls(std::string str, int size, int line);
    static void                     printMap(std::vector<std::string> map);
    static MapGenerator             *getInstance();
    static std::string deleteDestructibleWallsNearCharacter(std::string str, int size, int line);

protected:
private:
    MapGenerator();
    ~MapGenerator();
    static MapGenerator *_instance;
};
#endif /* !MAPGENERATOR_HPP_ */
