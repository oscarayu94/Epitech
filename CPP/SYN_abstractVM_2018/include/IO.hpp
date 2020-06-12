/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** IO
*/

#ifndef IO_HPP_
#define IO_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

class IO {
	public:
		IO();
		~IO();
		std::vector<std::string>orders;
		int grabFile(char *argv);
		int mainProgram();

	protected:
	private:
};

#endif /* !IO_HPP_ */
