/*
** EPITECH PROJECT, 2019
** SYN_autoCompletion_2018
** File description:
** Tools
*/

#include "../include/Tools.hpp"

Tools::Tools()
{
}

Tools::~Tools()
{
}

void Tools::printAMap(map)
{
    map<string, string>::iterator itr;
    for (itr = map.begin(); itr != map.end(); itr++)
    {
        cout << '\t' << itr->first;
        cout << '\t' << itr->second << '\n';
    }
}