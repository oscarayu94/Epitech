/*
** EPITECH PROJECT, 2020
** CPU
** File description:
** cpp
*/

#include "Cpu.hpp"

Cpu::Cpu()
{
}

Cpu::~Cpu()
{
}

void Cpu::display()
{
    refresh();
    mvwprintw(box, 1, 1, info.c_str());
}

void Cpu::refresh()
{
    std::ifstream inFile;
    inFile.open("/proc/cpuinfo");
    std::string newString;;
    std::string _result;
    int _counter = 0;
    while(!inFile.eof()) { 
        getline(inFile, newString, '\n');
        if (newString.find("processor") != std::string::npos) {
            _result += "Cpu : " + std::to_string(_counter) + "\n";
            _counter++;
        }
        if (newString.find("model name") != std::string::npos || newString.find("cpu MHz") != std::string::npos) {
            _result += newString + "\n";
        }
    }
    inFile.close();
    info = _result;
}

std::string Cpu::getInfo()
{
    return (info);
}