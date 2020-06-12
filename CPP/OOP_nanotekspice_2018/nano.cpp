/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** by Luis Angel Macias de la Cruz
*/

#include <iostream>
#include <string>
#include "Errors.hpp"
#include "Components/Component.hpp"
#include "Components/LogicDoors.hpp"

int main(int ac, char **av)
{
    Component   c;
    if (ac > 1) {
        std::cout << av[1] << std::endl;
        
        if (ac > 2) {
            for (int i = 2; i < ac; i++) {
                std::cout << av[i] << std::endl;
            }
        }
    }
}