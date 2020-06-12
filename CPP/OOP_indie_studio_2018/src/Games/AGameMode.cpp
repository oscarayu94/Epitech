/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AGameMode
*/

#include "../../include/Games/AGameMode.hpp"

AGameMode::AGameMode(states::gameType type)
    : isCameraSet(false), createdSky(false), _type(type), isGameOver(false)
{}

APlayerNode  *AGameMode::setPlayer(states::playerType type, vector3df position, irr::io::path path, std::string name)
{
    APlayerNode *play;
    if (type == states::COM)
        play = new AINode(_device, position, type, path);
    else
        play = new PlayerNode(_device, position, type, path);;
    play->setReceiver(_receiver);
    play->createMoves();
    c8 *test = const_cast<c8*>(name.c_str());
    play->setName(test);
    return play;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#else
void    AGameMode::playMusic(std::string musicname)
{
    _playlist[musicname]->play();
}

void    AGameMode::stopMusic(std::string musicname)
{
    _playlist[musicname]->stop();
}
#endif

void    AGameMode::setReceiver(EventReceiver *receiver)
{
    _receiver = receiver;
}

void    AGameMode::setDevice(IrrlichtDevice *device)
{
    _device = device;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#else
void    AGameMode::setPlaylist(std::map<std::string, Sfx*> playlist)
{
    _playlist = playlist;
}
#endif

void    AGameMode::showPlayerStats(APlayerNode *player, rect<s32> pos)
{
    IGUIEnvironment *env = _device->getGUIEnvironment();

    if (player->getHealthPoints() <= 0) {
        core::stringw   str(L"");
        IGUIStaticText  *text = env->addStaticText(str.c_str(), pos, false);
        str += player->getSceneNode()->getName();
        str += " is dead";
        text->setText(str.c_str());
        text->setOverrideColor(SColor(255, 255, 255, 255));
        player->getSceneNode()->setVisible(false);
    }
}

void    AGameMode::loadGameMap()
{
    std::vector<std::string>    map;

    if (_map.empty()) {
        map = _map_array;
        //map = MapGenerator::generate_map(20);
        for (std::vector<std::string>::iterator it = map.begin(); it != map.end(); ++it) {
            for (std::string::iterator c = it->begin(); c != it->end(); ++c) {
                if (*c == '#')
                    _map.push_back(new CubeNode(_device, vector3df(10 * (it - map.begin()), 0, 10 * (c - it->begin())), "../assets/wall.jpg", 0));
                if (*c == 'x')
                    _map.push_back(new CubeNode(_device, vector3df(10 * (it - map.begin()), 0, 10 * (c - it->begin())), "../assets/wall2.jpg", 1));
            }
        }
        ISceneNode *node = _device->getSceneManager()->addCubeSceneNode(10.0f, 0, -1, vector3df(100, -10, 100), vector3df(0, 0, 0), vector3df(21.0f, 1.0f, 21.0f));;
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMaterialTexture(0, _device->getVideoDriver()->getTexture("../assets/floor.jpg"));
    }       
}

void    AGameMode::setCamera()
{
    if (!isCameraSet) {
        _cam = _device->getSceneManager()->addCameraSceneNode(0, vector3df(101, 170, 100), vector3df(100, 0, 100));
        isCameraSet = true;
    }
}

void    AGameMode::setSky()
{
    if (!createdSky) {
        _device->getVideoDriver()->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
        _device->getSceneManager()->addSkyBoxSceneNode(
            _device->getVideoDriver()->getTexture("../assets/sky/irrlicht2_up.jpg"),
            _device->getVideoDriver()->getTexture("../assets/sky/irrlicht2_dn.jpg"),
            _device->getVideoDriver()->getTexture("../assets/sky/irrlicht2_lf.jpg"),
            _device->getVideoDriver()->getTexture("../assets/sky/irrlicht2_rt.jpg"),
            _device->getVideoDriver()->getTexture("../assets/sky/irrlicht2_ft.jpg"),
            _device->getVideoDriver()->getTexture("../assets/sky/irrlicht2_bk.jpg"));
        _device->getVideoDriver()->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);
        createdSky = true;
    }
}

void    AGameMode::setUp()
{
    loadGameMap();
    setCamera();
    setSky();
    _device->getVideoDriver()->beginScene(true, true, SColor(255, 0, 0, 0));
    _device->getSceneManager()->drawAll();
    _device->getGUIEnvironment()->drawAll();
    _device->getVideoDriver()->endScene();
}

void    AGameMode::saveGame()
{
    load_map.saveGame(_map_array, _device, _type);
}

void    AGameMode::checkGameOver(std::string musicToStop)
{
    if (_player->isPlayerDead() && !_playertwo->isPlayerDead() && !_playerthree->isPlayerDead() && !_playerfour->isPlayerDead()) {
        setWinner(_player->getSceneNode());
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #else
        stopMusic(musicToStop);
        #endif
        // _device->getSceneManager()->clear();
        // _device->getGUIEnvironment()->clear();
        _receiver->setScenario(states::GAMEOVER);
    }
    else if (!_player->isPlayerDead() && _playertwo->isPlayerDead() && !_playerthree->isPlayerDead() && !_playerfour->isPlayerDead()) {
        setWinner(_playertwo->getSceneNode());
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #else
        stopMusic(musicToStop);
        #endif
        // _device->getSceneManager()->clear();
        // _device->getGUIEnvironment()->clear();
        _receiver->setScenario(states::GAMEOVER);
    }
    else if (!_player->isPlayerDead() && !_playertwo->isPlayerDead() && _playerthree->isPlayerDead() && !_playerfour->isPlayerDead()) {
        setWinner(_playerthree->getSceneNode());
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #else
        stopMusic(musicToStop);
        #endif
        // _device->getSceneManager()->clear();
        // _device->getGUIEnvironment()->clear();
        _receiver->setScenario(states::GAMEOVER);
    }
    else if (!_player->isPlayerDead() && !_playertwo->isPlayerDead() && !_playerthree->isPlayerDead() && _playerfour->isPlayerDead()) {
        setWinner(_playerfour->getSceneNode());
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #else
        stopMusic(musicToStop);
        #endif
        // _device->getSceneManager()->clear();
        // _device->getGUIEnvironment()->clear();
        _receiver->setScenario(states::GAMEOVER);
    }
}

vector3df    AGameMode::getPlayerPos(int type)
{
    vector3df position;

    std::cout << "\n\n\ntype:" <<(int)type<<"\n\n";

    for (int i = 0; i != _map_array.size(); i++)
        for (int g = 0; g != _map_array[i].size(); g++)
            if (_map_array[i][g] == (int)type + 48) {
                position.X = (i - 1) * 10;  
                position.Z = (g - 1) * 10;
            }
    position.Y = 0;
    return position;
}