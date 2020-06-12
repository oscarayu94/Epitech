/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** IO
*/

#include "../include/IO.hpp"
#include "../include/Chipset.hpp"

IO::IO()
{
}

IO::~IO()
{
}

bool isEmpty(std::ifstream& inFile)
{
    return inFile.peek() == std::ifstream::traits_type::eof();
}

int IO::grabFile(char *argv)
{   
    class Chipset chipset;
    std::ifstream inFile;
    inFile.open(argv);
    if (!inFile || isEmpty(inFile) == true) {
        return 84;
    }
    for (std::string line; getline(inFile,line); )
    {
        if (chipset.storeMyInput(line) == 84)
            return(84);
        else if (chipset.storeMyInput(line) == 1)
            continue;
    }
    std::vector<std::string>::iterator it;
    for (auto it = IO::orders.cbegin(); it != IO::orders.cend(); it++){
        std::cout << *it << std::endl;
    }
    std::cout << "Checking basic functions " << argv << std::endl;
    return 0;
}

int IO::mainProgram() 
{
    std::cout << "Checking basic functions 2" << std::endl;
    return 0;
}