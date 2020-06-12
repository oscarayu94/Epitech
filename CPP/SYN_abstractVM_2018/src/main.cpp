/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** main
*/

#include "../include/IO.hpp"

int main(int ac, char** argv)
{
    class IO IO;
    if (ac == 2){
        if (IO.grabFile(argv[1]) == 84)
            return 84;
        else if (IO.grabFile(argv[1]) == 0)
            return 0;
    }
    else if (ac == 1){
        if (IO.mainProgram() == 84)
            return 84;
        else
            return 0;
    }   
    return 84;
}