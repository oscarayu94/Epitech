/*
** EPITECH PROJECT, 2020
** HostIUserName
** File description:
** cpp
*/

#include "HostUserName.hpp"


HostUserName::HostUserName()
{
}

HostUserName::~HostUserName()
{
}

void HostUserName::refresh()
{
    char tmp[256];
    gethostname(tmp, sizeof(tmp));
    hostname = tmp;
    username = getlogin();
}

void HostUserName::setHostname(std::string hostname)
{
    this->hostname = hostname;
}

void HostUserName::setUsername(std::string username)
{
    this->username = username;
}

std::string HostUserName::getHostname()
{
    return (this->hostname);
}

std::string HostUserName::getUsername()
{
    return (this->username);
}

void HostUserName::display()
{
    refresh();
    std::string tmp = "Hostname: " + getHostname();
    mvwprintw(box, 1, 1, tmp.c_str());
    tmp = "Username: " + getUsername();
    mvwprintw(box, 2, 1, tmp.c_str());
}