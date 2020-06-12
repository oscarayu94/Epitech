/*
** EPITECH PROJECT, 2020
** MyGKrellm
** File description:
** hpp
*/

#ifndef MYGKRELLM_HPP_
#define MYGKRELLM_HPP_

#include <Interfaces/IMonitorModule.hpp>
#include <Interfaces/IMonitorDisplay.hpp>
#include "Sfml/SfmlMode.hpp"
#include "Ncurses/NcursesMode.hpp"
#include <iostream>

#define TEXT_MODE 1
#define GRAPHICAL_MODE 2
#define CLEAR_TERM std::cout << "\033[2J" << "\033[1;1H";
#define FONT "assets/font.ttf"
void run_ncurses();
void run_sfml();
void print_help(char **av);
int get_mode();
void run_sfml();
void run_ncurses();
#endif /* !MYGKRELLM_HPP_ */
