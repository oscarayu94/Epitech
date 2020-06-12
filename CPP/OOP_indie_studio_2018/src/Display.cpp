/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Display
*/

#include "../include/Display.hpp"

Display::Display() :   _is_load_game(false)
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    initPlaylist();
    #endif
    _device = createDevice(EDT_OPENGL, dimension2d<u32>(1280, 720));

    if (!_device)
        exit(84);
    initDriver();
    initSceneManager();
    initGUIEnvironment();
    setTitle("Polianum");
    _receiver = new EventReceiver(_device, &_is_load_game);
    _device->setEventReceiver(_receiver);
    _scenario = states::INTRO;
    _game = NULL;
    _intro = NULL;
    _winner = NULL;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#else
void    Display::initPlaylist()
{
    _playlist["menu_loop"] = new Sfx("menu_loop", true);
    _playlist["battle_royale"] = new Sfx("battle_royale", true);
    _playlist["2v2"] = new Sfx("2v2", true);
    _playlist["spectator"] = new Sfx("spectator", true);
    _playlist["begin"] = new Sfx("begin", false);
}
#endif

void    Display::initDriver()
{
    _driver = _device->getVideoDriver();

    if (!_driver)
        exit(84);
}

void    Display::initSceneManager()
{
    _sceneManager = _device->getSceneManager();

    if (!_sceneManager)
        exit(84);
}

void    Display::initGUIEnvironment()
{
    _guiEnv = _device->getGUIEnvironment();

    if (!_guiEnv)
        exit(84);        
}

void    Display::setTitle(std::string title)
{
    std::wstring wideTitle = std::wstring(title.begin(), title.end());
    _device->setWindowCaption(wideTitle.c_str());
}

void    Display::setFontStyle(const irr::io::path path)
{
    IGUISkin    *skin = _guiEnv->getSkin();
    IGUIFont    *font = _guiEnv->getFont(path);

    if (!font)
        exit(84);
    if (!skin)
        exit(84);
    skin->setFont(font);
    skin->setFont(_guiEnv->getBuiltInFont(), EGDF_TOOLTIP);
}

void    Display::initMainMenuAssets()
{
    _guiEnv->addImage(_driver->getTexture("../assets/logo.png"), position2d<int>(0, -200));
    _guiEnv->addButton(rect<s32>(600, 280, 670, 280 + 32), 0, states::NEWGAME, L"New Game");
    _guiEnv->addButton(rect<s32>(600, 330, 670, 330 + 32), 0, states::LOADGAME, L"Load Game");
    _guiEnv->addButton(rect<s32>(600, 380, 670, 380 + 32), 0, states::QUITGAME, L"Quit");
}

void    Display::runIntro()
{
    if (_scenario == states::INTRO) {
        if (_intro == NULL)
            _intro = new Intro(_device, _receiver);
        _intro->play();
        drawAll(SColor(255, 255, 255, 255));
    }
}

void    Display::runMainMenu()
{
    if (_scenario == states::MAINMENU) {
        setFontStyle("../assets/fonthaettenschweiler.bmp");        
        initMainMenuAssets();
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #else
        _playlist["menu_loop"]->play();
        #endif
        drawAll(SColor(255, 100, 101, 140));
    }
}

void    Display::goBackTo(states::scenario scene)
{
    if (_receiver->IsKeyDown(KEY_ESCAPE)) {
        _guiEnv->clear();
        _receiver->setScenario(scene);
    }
}

void    Display::runSelectMode()
{
    if (_scenario == states::GAMESELECT) {
        _guiEnv->addButton(rect<s32>(600, 320, 600 + 80, 320 + 32), 0, states::BATTLEROYALE, L"Battle Royale");
        _guiEnv->addButton(rect<s32>(600, 360, 600 + 80, 360 + 32), 0, states::TWOVSTWO, L"TwovsTwo");
        _guiEnv->addButton(rect<s32>(600, 400, 600 + 80, 400 + 32), 0, states::SPECTATOR, L"Spectator");
        goBackTo(states::MAINMENU);
        drawAll(SColor(255, 0, 150, 50));
    }
}

void    Display::runGameMode()
{
    if (_scenario == states::GAMEMODE) {
        if (_game == NULL) {
            if (!_is_load_game)
                _map_array = MapGenerator::generateMap(20);
            else {
                _map_array = LoadMap::getMap();
                _receiver->setGame(static_cast<states::gameType>(LoadMap::getGameId()));
            }
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            #else
            _playlist["menu_loop"]->stop();
            #endif
            if (_receiver->getSelectedGame() == states::BATTLEROYALE)
                _game = new BattleRoyale(_map_array);
            if (_receiver->getSelectedGame() == states::TWOVSTWO)
                _game = new TwoVsTwo(_map_array);
            if (_receiver->getSelectedGame() == states::SPECTATOR)
                _game = new Spectator(_map_array);
            _game->setDevice(_device);
            _game->setReceiver(_receiver);
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            #else
            _game->setPlaylist(_playlist);
            _playlist["begin"]->play();
            #endif
        }
        _game->setUp();
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        _game->run();
        #else
        if (_playlist["begin"]->getStatus() == 0)
            _game->run();
        #endif
        // #ifdef _WIN32
        // _game->run();
        // #endif
    }
}

void    Display::runGameOver()
{
    if (_scenario == states::GAMEOVER) {
        IGUIInOutFader  *fade = _guiEnv->addInOutFader();
        fade->setColor(SColor(255, 139, 0, 0));
        fade->fadeOut(1500);
        
        core::stringw   str(L"");
        str += "The Winner is...\n";
        str += _game->getWinner()->getName();
        str += "\nEverybody else should be ashamed...";

        _guiEnv->addStaticText(str.c_str(), rect<s32>(500, 300, 725, 400), false)->setOverrideColor(SColor(255, 255, 255, 255));
        _guiEnv->addButton(rect<s32>(500, 400, 750, 400 + 32), 0, states::QUITGAME, L"I beg you... please exit the game");
        _guiEnv->addButton(rect<s32>(500, 450, 750, 450 + 32), 0, states::NEWGAME, L"Or maybe do you wanna try fate again?");

        drawAll(SColor(255, 139, 0, 0));
    }
}

void    Display::drawAll(SColor color)
{
    _driver->beginScene(true, true, color);
    _sceneManager->drawAll();
    _guiEnv->drawAll();
    _driver->endScene();
}

void    Display::run()
{
    setFontStyle("../assets/fonthaettenschweiler.bmp");
    while (_device->run() && _driver) {
        _scenario = _receiver->getCurrentScenario();
        runIntro();
        runMainMenu();
        runSelectMode();
        runGameMode();
        runGameOver();
        //       _game->saveGame();
    }
    if (_game)
        _game->saveGame();
    _device->drop();
}

Display::~Display()
{
}
