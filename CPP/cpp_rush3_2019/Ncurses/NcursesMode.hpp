/*
** EPITECH PROJECT, 2020
** ncurses_mode
** File description:
** hpp
*/

#ifndef NCURSESMODE_HPP_
#define NCURSESMODE_HPP_

#include "MyGKrellm.hpp"
#include "../Datas/Cpu.hpp"
#include "../Datas/DateTime.hpp"
#include "../Datas/HostUserName.hpp"
#include "../Datas/KernelSystem.hpp"
#include "../Datas/MonitorCore.hpp"
#include "../Datas/Network.hpp"
#include "../Datas/Ram.hpp"
#include <ncurses.h>

class NcursesMode : public IMonitorDisplay {
    public:
    NcursesMode();
    virtual ~NcursesMode();
    void display();
    void run();
    void do_subwin();
    void createBox();
    void print();
    void refreshPrint();
protected:
    MonitorCore dataMonitorCore;
    HostUserName dataHostUserName;
    KernelSystem dataKernelSystem;
    DateTime dataDateTime;
    Cpu dataCpu;
    Ram dataRam;
    Network dataNetwork;
};



#endif /* !NCURSES_MODE_HPP_ */
