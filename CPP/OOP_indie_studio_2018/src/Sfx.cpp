/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Sfx
*/

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#else

#include "../include/Sfx.hpp"

Sfx::Sfx(std::string name, bool loop)
    :   _isPlaying(false), _path("../assets/sound/" + name + ".wav")
{
    _buffer.loadFromFile(_path);
    _sound.setBuffer(_buffer);
    _sound.setLoop(loop);
    std::cout << "[" << name << "]" << " has been added to the playlist" << std::endl;
}

void    Sfx::play()
{
    if (!_isPlaying) {
        _sound.play();
        _isPlaying = true;
    }
}

void    Sfx::stop()
{
    if (_isPlaying) {
        _sound.stop();
        _isPlaying = false;
    }
}

void    Sfx::setVolume(float volume)
{
    _sound.setVolume(volume);
}

#endif