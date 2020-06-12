/*
** EPITECH PROJECT, 2020
** CPU
** File description:
** hpp
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include <ncurses.h>
#include <iostream>
#include <fstream>

class Cpu {
	public:
		Cpu();
		~Cpu();
		WINDOW *box;
		void display();
		void refresh();
		std::string getInfo();
	protected:
		std::string info;
	private:
};

#endif /* !CPU_HPP_ */
