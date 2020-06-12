/*
** EPITECH PROJECT, 2020
** HostUserName
** File description:
** hpp
*/

#ifndef HOSTUSERNAME_HPP_
#define HOSTUSERNAME_HPP_

#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <iostream>

class HostUserName {
	public:
		HostUserName();
		~HostUserName();
		void refresh();
		void setHostname(std::string);
		void setUsername(std::string);
		std::string getHostname();
		std::string getUsername();
		void display();
		WINDOW *box;
	protected:
		std::string hostname;
		std::string username;
	private:
};

#endif /* !HOSTUSERNAME_HPP_ */
