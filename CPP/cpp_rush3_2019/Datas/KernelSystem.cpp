/*
** EPITECH PROJECT, 2020
** KernelSystem
** File description:
** cpp
*/

#include "KernelSystem.hpp"

KernelSystem::KernelSystem()
{
}

KernelSystem::~KernelSystem()
{
}

void KernelSystem::display()
{
    refresh();
    std::string tmp = "Os Name: " + getOsName();
    mvwprintw(box, 1, 1, tmp.c_str());
    tmp = "Kernel Version: " + getKernel();
    mvwprintw(box, 2, 1, tmp.c_str());
}

std::string KernelSystem::getOsName()
{
    return (OsName);
}

std::string KernelSystem::getKernel()
{
    return (kernel);
}

void KernelSystem::refresh()
{
    struct utsname info;
    uname(&info);
    OsName = info.sysname;
    kernel = info.release;

}
