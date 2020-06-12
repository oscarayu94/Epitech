/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2019
** File description:
** src/groundhog.cpp
*/

#include <iomanip>
#include "../include/groundhog.hpp"

void display_final(int switches, std::vector<double> weird)
{
    std::cout << "Global tendency switched " << switches << " times" << std::endl;
    if (!weird.empty()) {
        std::cout << std::setprecision(1) << std::fixed;
        std::cout << "5 weirdest values are [";
        for (int i = 0; i < 4; ++i)
            std::cout << weird[i] << ", ";
        std::cout << weird[4] << "]" << std::endl;
    }
}

void print_result(double g, double r, double s, bool notReal, bool less, bool switches)
{
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "g=";
    notReal ? std::cout << "nan" : std::cout << g;
    std::cout << "\tr=";
    std::cout << std::setprecision(0) << std::fixed;
    notReal ? std::cout << "nan" : std::cout << r;
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "%\ts=";
    less ? std::cout << "nan" : std::cout << s;
    switches ? std::cout << "\ta switch occurs" << std::endl : std::cout << std::endl;
}

double calcTempEvolution(const std::vector<double> &list, int period)
{
    double result = 0;
    int size = list.size();
    int i = size - period;
    double tmp;

    for (i; i != size; ++i) {
        tmp = list[i] - list[i - 1];
        if (tmp > 0)
            result += tmp;
    }
    result /= period;

    return result;
}

double calcRelativeTemp(std::vector<double> list, int period)
{
    int size = list.size();
    double tmp1 = list[size - period - 1];
    double tmp2 = list[size - 1];

    return (round(
            (tmp2 - tmp1)
           / tmp1 * 100)
           );
}

double calcStandardDerivation(std::vector<double> list, int period)
{
    double tmp1 = 0;
    double tmp2 = 0;
    int size = list.size();

    for (int i = (size - period); i < size; ++i) {
        if (i >= 0) {
            tmp1 += list[i];
            tmp2 += list[i] * list[i];
        }
    }

    return sqrt(
            (tmp2 / period)
            - (tmp1 / period)
              * (tmp1 / period)
    );
}

void groundhog(int period)
{
    char input[128];
    std::vector<double> list;
    std::vector<double> weird;
    int switches = 0;
    double g = 0;
    double r = 0;
    double s = 0;
    double last = r;
    float value = 0;

    while (true) {
        std::scanf("%s", input);
        if (std::strcmp(input, "STOP") == 0)
            break;
        value = std::atof(input);
        if (value != 0) {
            list.emplace_back(std::atof(input));
            if (list.size() > period) {
                g = calcTempEvolution(list, period);
                last = r;
                r = calcRelativeTemp(list, period);
            }
            s = calcStandardDerivation(list, period);
            if (((last < 0 && r >= 0) || (last >= 0 && r < 0)) && last != 0) {
                ++switches;
                print_result(g, r, s, list.size() <= period, list.size() < period, true);
            } else
                print_result(g, r, s, list.size() <= period, list.size() < period, false);
        }
    }
    display_final(switches, weird);
}