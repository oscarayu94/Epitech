/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Chipset
*/

/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Chipset
*/

#include "../include/Chipset.hpp"

Chipset::Chipset()
{
}

Chipset::~Chipset()
{
}

int Chipset::storeMyInput(std::string line)
{
    int i = 0;
    int semi = 0;
    bool comment = false;
    while (line[i] != '\0'){
        if (line[i] == ';'){
            semi++;
            comment = true;
        }
        if (semi == 2)
            return 0;
        i++;
    }
    if (line.compare("exit"))
        return 0;
    else if (comment == true)
        return 1;
}