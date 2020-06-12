/*
** EPITECH PROJECT, 2020
** Ram
** File description:
** hpp
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>  

class Ram {
	public:
		Ram();
		~Ram();
		void display();
		void refresh();
		std::string getInfo();
		WINDOW *box;
	protected:
		std::string info;
	private:
};

#endif /* !RAM_HPP_ */
