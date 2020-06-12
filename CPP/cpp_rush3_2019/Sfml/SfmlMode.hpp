/*
** EPITECH PROJECT, 2020
** sfml mode
** File description:
** hpp
*/

#ifndef SFML_MODE_HPP_
#define SFML_MODE_HPP_

#include "MyGKrellm.hpp"
#include "../Datas/Cpu.hpp"
#include "../Datas/DateTime.hpp"
#include "../Datas/HostUserName.hpp"
#include "../Datas/KernelSystem.hpp"
#include "../Datas/MonitorCore.hpp"
#include "../Datas/Network.hpp"
#include "../Datas/Ram.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SfmlMode : public IMonitorDisplay {
public:
    SfmlMode();
    virtual ~SfmlMode();
    void setMessage(std::string);
    sf::Text getMessage();
    void getEvent();
    void clearWindow();
    void draw(sf::Text);
    void display();
    void run();
    void print(int char_size, int x, int y, std::string str);
protected:
    sf::RenderWindow *window;
    sf::Text message;
    sf::Font font;
    sf::Event event;
    MonitorCore dataMonitorCore;
    HostUserName dataHostUserName;
    KernelSystem dataKernelSystem;
    DateTime dataDateTime;
    Cpu dataCpu;
    Ram dataRam;
    Network dataNetwork;
};


#endif /* !SFML_MODE_HPP_ */
