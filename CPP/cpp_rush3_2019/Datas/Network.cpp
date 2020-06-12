/*
** EPITECH PROJECT, 2020
** Network
** File description:
** cpp
*/

#include "Network.hpp"

Network::Network()
{
}

Network::~Network()
{
}


void Network::display()
{
    refresh();
    mvwprintw(box, 1, 1, "Networks Used:");
    mvwprintw(box, 2, 1, info.c_str());
}

std::vector<int> parseNumbers(std::string newString)
{
    std::vector<int> comp;
    std::stringstream ss;
    ss << newString;
    std::string temp;
    std::string numb;
    int found;
    while (!ss.eof()) {
        ss >> temp;
        if (std::stringstream(temp) >> found){
            comp.push_back(found);
        }
    }
    return (comp);
}

void printVector(std::vector<int> const &numbers)
{
    for(size_t i = 0; i < numbers.size(); i++)
        if (i == 0 || i == 1 || i == 2 || i == 8 || i == 9 || i == 10)
            std::cout << "\t" << numbers.at(i) << "\t";
}

void parseFile(std::ifstream &inFile)
{
    std::string newString;;
    int compressed_ocurrences = 0;
    std::vector<int> numbers;

    std::cout << "Interface\tBytes received\tPackets received\tErrors\tBytes sent\tPackets sent\tErrors";


    while(!inFile.eof()) {
        getline(inFile, newString, '\n');
        if (newString.find("compressed"))
            compressed_ocurrences++;
        if (compressed_ocurrences > 2){
            std::string interface = newString.substr(0,(newString.find_first_of(":")+1));
            std::cout << interface;
            numbers = parseNumbers(newString);
        }
        printVector(numbers);
        std::cout << std::endl;
    }
}

void Network::refresh()
{
    std::ifstream inFile;
    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

    inFile.open("/proc/net/dev");
    parseFile(inFile);
    inFile.close();
    std::cout.rdbuf( old );
    info = buffer.str();
}

std::string Network::getInfo()
{
    return (info);
}
