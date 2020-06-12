/*
** EPITECH PROJECT, 2020
** monitorcore
** File description:
** hpp
*/

#ifndef MONITORCORE_HPP_
#define MONITORCORE_HPP_

#include <ncurses.h>
#include <string>
#include <iostream>
#include <dirent.h>
#include <fnmatch.h>
#include <string.h>
#include <sstream>      

class MonitorCore {
	public:
		MonitorCore();
		~MonitorCore();
		void display();
		void refresh();
		std::string getInfo();
		WINDOW *box;
	protected:
		std::string info;
	private:
};

#endif /* !MONITORCORE_HPP_ */
