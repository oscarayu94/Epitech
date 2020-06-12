/*
** EPITECH PROJECT, 2020
** DateTime
** File description:
** cpp
*/

#include "DateTime.hpp"

DateTime::DateTime()
{
}

DateTime::~DateTime()
{
}

void DateTime::refresh()
{
    time_t rawtime;   
    time (&rawtime);
    struct tm *timeinfo = localtime (&rawtime);
    char time_info[64]; 
    strftime(time_info, sizeof(time_info), "%c", timeinfo);
    dateTime = time_info;
}

void DateTime::display()
{
    refresh();
    mvwprintw(box, 1, 1, "Date:");
    mvwprintw(box, 2, 1, dateTime.c_str());
}

std::string DateTime::getDateTime()
{
    return (dateTime);
}