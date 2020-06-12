/*
** EPITECH PROJECT, 2019
** map t3n34q5p4
** File description:
** map generator by oriol
*/

#include "../include/MapGenerator.hpp"

MapGenerator::MapGenerator()
{
}

MapGenerator::~MapGenerator()
{
}

std::string MapGenerator::addCharacters(std::string str, int size, int line)
{
    if (line == 1) {
        str.replace(1, 1, "1");
        str.replace(size - 2, 1, "2");
    }
    else if (line == size - 2) {
        str.replace(1, 1, "3");
        str.replace(size - 2, 1, "4");
    }
    return str;
}

std::string MapGenerator::deleteDestructibleWallsNearCharacter(std::string str, int size, int line)
{
    if (line == 1 || line == size - 2) {
        str.replace(2, 1, " ");
        str.replace(size - 3, 1, " "); 
    } else if (line == 2 || line == size - 3)
        str.replace(1, 1, " "); 
    return str;
}

std::string MapGenerator::setDestructibleWalls(std::string str, int size, int line)
{
    int iSecret;
    std::string characters = "1234#";
    std::string ptr;

    if (line == 0 || line == size - 1)
        return str;
    for (int a = 0; a < size; a++) {
        ptr.clear();
        ptr = ptr + str[a];
        srand (a * line * size *  std::time(0));
        iSecret = rand() % 10 + 1;
        
        if (iSecret > 7 && a != 0 && a != size - 1 && 
            std::string(ptr).find_first_not_of(characters) != (size_t)-1) {
            str.replace(a, 1, "x");
        }
    }
    str = deleteDestructibleWallsNearCharacter(str, size, 1);

    return (str);
}

std::vector<std::string> MapGenerator::generateMap(int size)
{
    std::string str;
    std::vector<std::string> _map;

    if (size % 2 == 0)
        size++;
    for (int i = 0; i < size; i++) {
        str.clear();
        for (int a = 0; a < size; a++)
            str = str.append("#");
        for (int g = 1; i != 0 && i != size -1 && g < size -1 ; g++)
            if (g % 2 != 0 || i % 2 != 0)
                str.replace(g, 1, " ");          // "this is an example string." (1)
        str = addCharacters(str, size, i); 
        str = setDestructibleWalls(str, size, i); 
        _map.push_back(str);
    }
    // print_map(_map);
    return _map;
}

void    MapGenerator::printMap(std::vector<std::string> _map)
{
    std::cout << "start print map\n";
    for (std::string a : _map)
        std::cout << a << std::endl;
}

MapGenerator    *MapGenerator::getInstance()
{
    return new MapGenerator();
}
