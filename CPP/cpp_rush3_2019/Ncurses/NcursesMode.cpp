/*
** EPITECH PROJECT, 2020
** Ncurses
** File description:
** cpp
*/

#include "NcursesMode.hpp"
#include "../MyGKrellm.hpp"

NcursesMode::NcursesMode()
{
    initscr();
    curs_set(0);
    nodelay(stdscr, true);
}

NcursesMode::~NcursesMode()
{
}

void NcursesMode::run()
{   
    while (true) {
        display();
        if (getch() == 'q')
            break;
        usleep(500000);
        clear();
    }
    endwin();
}

void NcursesMode::do_subwin()
{
    dataMonitorCore.box = subwin(stdscr, LINES, COLS / 3, 0, COLS / 3 * 2);       
    dataHostUserName.box = subwin(stdscr, (LINES / 12), COLS / 3, LINES / 12, 0);
    dataKernelSystem.box = subwin(stdscr, LINES / 12, COLS / 3, LINES / 12, COLS / 3);
    dataDateTime.box = subwin(stdscr, (LINES / 12), COLS / 3, 0, 0);
    dataCpu.box = subwin(stdscr, LINES / 2, COLS / 3, LINES / 12 * 2, 0);
    dataRam.box = subwin(stdscr, LINES / 6, COLS / 3, LINES / 3, COLS / 3);
    dataNetwork.box = subwin(stdscr, LINES / 3, COLS / 3 * 2, LINES / 3 * 2, 0);

}

void NcursesMode::createBox()
{
    box(dataMonitorCore.box, ACS_VLINE, ACS_HLINE);
    box(dataHostUserName.box, ACS_VLINE, ACS_HLINE);
    box(dataKernelSystem.box, ACS_VLINE, ACS_HLINE);
    box(dataDateTime.box, ACS_VLINE, ACS_HLINE);
    box(dataCpu.box, ACS_VLINE, ACS_HLINE);
    box(dataRam.box, ACS_VLINE, ACS_HLINE);
    box(dataNetwork.box, ACS_VLINE, ACS_HLINE);
}

void NcursesMode::print()
{
    dataMonitorCore.display();
    dataHostUserName.display();
    dataKernelSystem.display();
    dataDateTime.display();
    dataCpu.display();
    dataRam.display();
    dataNetwork.display();
}

void NcursesMode::refreshPrint()
{
    wrefresh(dataMonitorCore.box);
    wrefresh(dataHostUserName.box);
    wrefresh(dataKernelSystem.box);
    wrefresh(dataDateTime.box);
    wrefresh(dataCpu.box);
    wrefresh(dataRam.box);
    wrefresh(dataNetwork.box);
}
void NcursesMode::display()
{
    do_subwin();
    createBox();
    print();
    refreshPrint();
}
