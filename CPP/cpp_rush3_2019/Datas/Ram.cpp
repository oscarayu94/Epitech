/*
** EPITECH PROJECT, 2020
** Ram
** File description:
** cpp
*/

#include "Ram.hpp"

Ram::Ram()
{
}

Ram::~Ram()
{
}

void Ram::display()
{
    refresh();
    mvwprintw(box, 1, 1, "Ram used:");
    mvwprintw(box, 2, 1, info.c_str());
}


void Ram::refresh()
{
    std::ifstream inFile;

    inFile.open("/proc/meminfo");
    std::string newString;;
    int tot_ram = 0;
    int free_ram = 0;
    int used_ram = 0;
    std::string tolStr = "";
    std::string freeStr = "";
    std::string _result;

    while(!inFile.eof()) {
        getline(inFile, newString, '\n');
        if (newString.find("MemTotal") != std::string::npos) {
            tolStr += newString + "\n";
            std::stringstream ss(tolStr);
            ss >> tolStr >> tot_ram;
        }
        if (newString.find("MemFree") != std::string::npos) {
            freeStr += newString + "\n";
            std::stringstream ss(freeStr);
            ss >> freeStr >> free_ram;
        }
        used_ram = tot_ram - free_ram;
        _result = std::to_string(used_ram) + "/" + std::to_string(tot_ram) + " kb";
    }
    info = _result;
    inFile.close();
}

std::string Ram::getInfo()
{
    return (info);
}
