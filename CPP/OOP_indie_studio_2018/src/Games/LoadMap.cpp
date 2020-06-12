/*
** EPITECH PROJECT, 2019
** load map
** File description:
** load map by oriol
*/

#include "../../include/Games/LoadMap.hpp"
#include "../../include/Games/AGameMode.hpp"

LoadMap::LoadMap()
{
}

LoadMap::~LoadMap()
{
}

void    LoadMap::updateMapWithNewDestructiveWalls(array<ISceneNode*> arr)
{
    int pos[2];

    for (int i = 0; i != arr.size(); i++) {
        pos[0] = arr[i]->getPosition().X / 10;
        pos[1] = arr[i]->getPosition().Z / 10;
        //std::cout << "id:" << arr[i]->getID() <<"," << pos[0] << "," << pos[1] << std::endl;

        if (arr[i]->getID() == 1)//destroyable
            _map_array[pos[0]][pos[1]] = 'x';
        else if (arr[i]->getID() == -1)
            _map_array[pos[0]][pos[1]] = ' ';
    }
}

void LoadMap::updateMapWithNewPlayerPos(array<ISceneNode*> arr)
{
    std::map<std::string,char> players_name;
    std::string s = "1234";
    int pos[2];

    players_name["PlayerOne"] = '1';
    players_name["PlayerTwo"] = '2';
    players_name["PlayerThree"] = '3';
    players_name["PlayerFour"] = '4';
    for (int i = 0; i != _map_array.size(); i++)
        for (int g = 0; g != _map_array[i].size(); g++)
            if (s.find(_map_array[i][g]) != std::string::npos)
                _map_array[i][g] = ' ';
    for (int i = 0; i != arr.size(); i++) {
        pos[0] = arr[i]->getPosition().X / 10 + 1;
        pos[1] = arr[i]->getPosition().Z / 10 + 1;
        if (arr[i]->getID() == 10) {
            std::cout << "name:" << arr[i]->getName() << ":" << pos[0] << ":" << pos[1] << "\n";
            std::cout << players_name[arr[i]->getName()];
            _map_array[pos[0]][pos[1]] = players_name[arr[i]->getName()];
        }
    }
}

void LoadMap::updateMapWithNewPos()
{   
    scene::ISceneManager *manager;
    array<ISceneNode*> arr;

    manager = _device->getSceneManager();
    manager->getSceneNodesFromType(ESNT_CUBE, arr);
    updateMapWithNewDestructiveWalls(arr);
   
    manager->getSceneNodesFromType(ESNT_ANIMATED_MESH, arr);
    updateMapWithNewPlayerPos(arr);
   
    std::cout << "jeere";
}
    
void LoadMap::saveGame( std::vector<std::string> map_array, IrrlichtDevice * device, states::gameType type)
{
    std::ofstream myfile;
    
    _map_array = map_array;
    _device = device;
    MapGenerator::printMap(_map_array);     
    myfile.open ("../prev_game/game.txt");
    if (!_map_array.empty())
        std::cout << "updated map\n";
        updateMapWithNewPos();
        MapGenerator::printMap(_map_array);     
        std::cout << "heeere" << std::endl;
        for (std::string a : _map_array) {
            //std::cout << a << std::endl;
            myfile << a << std::endl;
        }
    myfile << type << std::endl;
    //std::cout < "finalhehe\n"
    myfile.close();
    //std::vector<std::string> val;
    
}

std::vector<std::string> LoadMap::getMap()
{
    std::vector<std::string> map_array;
    std::string line;
    std::ifstream myfile ("../prev_game/game.txt");
    
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            if (line.size() > 0 && line[0] == '#')
                map_array.push_back(line);
            //std::cout << line << '\n';
        }
    }   
    myfile.close();
    return map_array;
}
int LoadMap::getGameId()
{
    int game = 0;
    std::string line;
    std::ifstream myfile ("../prev_game/game.txt");
    
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            if (line.size() > 0 && line[0] != '#')
                game = std::stoi(line);
            //std::cout << line << '\n';
        }
    }   
    return game;
}