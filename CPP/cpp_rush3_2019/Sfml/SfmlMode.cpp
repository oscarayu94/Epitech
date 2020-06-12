/*
** EPITECH PROJECT, 2020
** sfml mode
** File description:
** cpp
*/

#include "SfmlMode.hpp"
#include <iostream>

SfmlMode::SfmlMode()
{
    window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "MyGKrellm");
    font.loadFromFile(FONT);
    message.setFont(font);
    message.setString("");
    window->setFramerateLimit (20);
    message.setCharacterSize(30); 
    message.setFillColor(sf::Color::White);
}

SfmlMode::~SfmlMode()
{
}

void SfmlMode::print(int char_size, int x, int y, std::string str)
{
        message.setCharacterSize(char_size); 
        message.setPosition(x, y);
        setMessage(str);
        draw(message);
}

void SfmlMode::run()
{
    while (window->isOpen()) {
        getEvent();
        clearWindow();
        dataDateTime.refresh();
        print(30, 0, 0, dataDateTime.getDateTime());
        dataHostUserName.refresh();
        print(30, 0, 40, "HostName: " + dataHostUserName.getHostname());
        print(30, 0, 80, "UserName: " + dataHostUserName.getUsername());
        dataKernelSystem.refresh();
        print(30, 400, 40, "Os Name: " + dataKernelSystem.getOsName());
        print(30, 400, 80,"Kernel Version: " + dataKernelSystem.getKernel());
        dataCpu.refresh();
        print(20, 0, 150, dataCpu.getInfo());
        dataMonitorCore.refresh();
        print(10, 1400, 0, dataMonitorCore.getInfo());
        dataRam.refresh();
        print(30, 700, 300, "RAM Used: " + dataRam.getInfo());
        dataNetwork.refresh();
        print(20, 500, 700, "Networks Used:\n" + dataNetwork.getInfo());
        draw(message);
        display();
    }
}

void SfmlMode::setMessage(std::string str)
{
    message.setString(str);
}


sf::Text SfmlMode::getMessage()
{
    return (message);
}

void SfmlMode::getEvent()
{
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void SfmlMode::clearWindow()
{
    window->clear();
}

void SfmlMode::draw(sf::Text message)
{
    window->draw(message);
}

void SfmlMode::display()
{
    window->display();
}