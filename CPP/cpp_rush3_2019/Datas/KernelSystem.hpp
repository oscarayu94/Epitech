/*
** EPITECH PROJECT, 2020
** KernelSystem
** File description:
** hpp
*/

#ifndef KERNELSYSTEM_HPP_
#define KERNELSYSTEM_HPP_

#include <ncurses.h>
#include <string>
#include <iostream>
#include <sys/utsname.h>

class KernelSystem {
	public:
		KernelSystem();
		~KernelSystem();
		void display();
		void refresh();
		std::string getOsName();
		std::string getKernel();
		WINDOW *box;
	protected:
	std::string OsName;
	std::string kernel;
	private:
};

#endif /* !KERNELSYSTEM_HPP_ */
