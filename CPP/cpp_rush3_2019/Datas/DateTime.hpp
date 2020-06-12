/*
** EPITECH PROJECT, 2020
** Datetime
** File description:
** hpp
*/

#ifndef DATETIME_HPP_
#define DATETIME_HPP_

#include <ncurses.h>
#include <bits/types/time_t.h>
#include <time.h>
#include <iostream>

class DateTime {
	public:
		DateTime();
		~DateTime();
		void display();
		void refresh();
		std::string getDateTime();
		WINDOW *box;
	protected:
		std::string dateTime;
	private:
};

#endif /* !DATETIME_HPP_ */
