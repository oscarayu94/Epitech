/*
** EPITECH PROJECT, 2019
** utils
** File description:
** bu pripo
*/

#include "Utils.hpp"
#include "../list.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{

}

int Utils::getCurrentSeconds()
{
    auto    current = std::chrono::high_resolution_clock::now();

    current = std::chrono::high_resolution_clock::now();
    int sec = std::chrono::duration_cast<std::chrono::seconds>(current - start).count();
    // std::cout << sec << " seconds" << std::endl;
    return sec;
}

bool	Utils::write_to_fd(std::string fifo, std::string to_write)
{
    int fd = open(fifo.c_str(), O_WRONLY, O_CREAT, O_TRUNC); 
    if (fd == -1) {
        std::cout << "error opening " << fifo << "\n";
        return false;
    }
    write(fd, to_write.c_str(), to_write.size());
    close (fd);
    return true;
}


std::string	Utils::read_from_fd(std::string fifo)
{
     char buf;
    std::string str;

    int fd = open(fifo.c_str(), O_RDONLY, O_CREAT, O_TRUNC); 
    if (fd == -1) {
        std::cout << "error opening " << fifo << "\n";
        return "";
    }
    // Read from FIFO 
    str.clear();        
    while (read(fd, &buf, 1) > 0 && buf != '\n' && buf != '\0')
        str += buf;
    close (fd);
    return str;
}

//template <class myType>

int Utils::num_charact(std::string &string, char character)
{
    int count = 0;

    for (auto a: string) {
        if (character == a)
            count++;
    }
    return count;
}


Utils *Utils::getInstance()
{
    if (instance == 0)
        instance = new Utils();
    return instance;
}