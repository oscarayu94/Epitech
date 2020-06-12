/*
** EPITECH PROJECT, 2020
** Network
** File description:
** hpp
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <ncurses.h>
#include <string>
#include <iostream>
#include <string.h>
#include <sstream> 
#include <fstream>
#include <vector>

class Network {
	public:
		Network();
		~Network();
		WINDOW *box;
		void display();
		void refresh();
		std::string getInfo();
	protected:
		std::string info;
	private:
};

#endif /* !NETWORK_HPP_ */
