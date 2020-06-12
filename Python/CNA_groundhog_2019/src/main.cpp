/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2019
** File description:
** src/main.cpp
*/

#include "../include/groundhog.hpp"

void groundhog(int period);

static void print_usage()
{
    printf("SYNOPSIS\n"
           "\t./groundhog period\n\n"
           "DESCRIPTION\n"
           "\tperiod\tthe number of days defining a period\n");
}

int main(int ac, char **ag)
{
    if (ac != 2)
        return EXIT_ERROR;
    else if (std::strcmp(ag[1], "-h") == 0)
        print_usage();
    else {
        ac = ac;
        if (isdigit(ag[1][0]) && std::atoi(ag[1]) >= 0 && std::atoi(ag[1]) <= 9)
            groundhog(std::atoi(ag[1]));
        else
            return EXIT_ERROR;
    }
	return EXIT_SUCCESS;
}
