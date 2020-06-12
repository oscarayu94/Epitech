/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** TwoVsAll
*/

#include "../../include/Games/TwoVsTwo.hpp"

TwoVsTwo::TwoVsTwo(std::vector<std::string> map_generator)
    : AGameMode(states::TWOVSTWO)
{
    _player = NULL;
    _playertwo = NULL;
    _playerthree = NULL;
    _playerfour = NULL;
    _map_array = map_generator;

}

void    TwoVsTwo::run()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #else
    playMusic("2v2");
    #endif
    _device->getGUIEnvironment()->addStaticText(L"HORAY 2 vs All\n'#' are unbreakable walls and 'x' are breakable", rect<s32>(800, 10, 950, 60), true)->setOverrideColor(SColor(255, 255, 255, 255));
}

