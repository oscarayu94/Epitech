/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Sfx
*/

#ifndef SFX_HPP_
#define SFX_HPP_

// #ifdef linux
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#else

#include <string>
#include <iostream>
#include "../include/SFML/Audio.hpp"

using namespace sf;

class Sfx {
public:
    Sfx(std::string name, bool loop);
    void    play();
    void    stop();
    void    setVolume(float volume);
    int     getStatus() { return (int)_sound.getStatus(); }

protected:
private:
    bool _isPlaying;
    std::string _path;
    SoundBuffer _buffer;
    Sound _sound;
};

#endif

#endif /* !SFX_HPP_ */
