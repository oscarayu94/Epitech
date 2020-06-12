/*
** EPITECH PROJECT, 2019
** 203hotline_2018
** File description:
** main
*/

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cmath>
#define __FLOAT128__


void factSimple(std::string data)
{
    std::cout << "Sorry, I can't do that" << std::endl;
}

void put_it_nice(long double result)
{
    auto str = std::to_string(result);
    str.erase(str.find_first_of('.'));
    std::cout << str << std::endl;
}

//int128 now definition: 
//unsingend _int128 result = 0;

long double n_amount(int n)
{
    long double n_final = n;
    for(int i = 1; i < n; i++) {
        n_final = n_final*i;
    }
    //std::cout << std::fixed;
    //std::cout << n_final << std::endl;
    return n_final;
}

long double k_amount(int k)
{
    long double k_final = k;
    for(int i = 1; i < k; i++) {
        k_final = k_final*i;
    }
    //std::cout << std::fixed;
    //std::cout << k_final << std::endl;
    return k_final;
}

long double nk_amount(int nk)
{
    long double nk_final = nk;
    for(int i = 1; i < nk; i++) {
        nk_final = nk_final*i;
    }
    //std::cout << std::fixed;
    //std::cout << nk_final << std::endl;
    return nk_final;
}

void factComplex(std::string first, std::string second)
{
    //first is n, second is k
    const char *first2 = first.c_str();
    const char *second2 = second.c_str();
    int n1 = std::atoi(first2);
    int k1 = std::atoi(second2);
    
    if (k1 > n1) {
        std::cout << k1 << "-combination of a " << n1 << " set:" << std::endl;
        std::cout << "0" << std::endl;
    }
    else if (k1 < n1) {
        int sub = n1 - k1;
        long double n = n_amount(n1);
        long double k = k_amount(k1);
        long double nk = nk_amount(sub);
        long double result = n/(k*nk);
        std::cout << k1 << "-combination of a " << n1 << " set:" << std::endl;
        //std::cout << std::fixed;
        put_it_nice(result);
        //std::cout << result << std::endl;
    }
    else if (k1 == n1) {
        //std::cout << k1 << "-combination of a " << n1 << " set:" << std::endl;
        std::cerr << "Error: Cannot divide by 0!" << std::endl;
    }
    //std::cout << first << std::endl;
    //std::cout << second << std:: endl;
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t\t./203 hotline [n k | d]" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\t\tn\tn value for the computation of (n k)" << std::endl;
    std::cout << "\t\tk\tk value for the computation of (n k)" << std::endl;
    std::cout << "\t\td\taverage duration of calls (in seconds)" << std::endl;
}

int main(int ac, char** av)
{
    int i = 0;
    // while (i < 26) {
    //     n_amount(i);
    //     i++;
    // }
    if (ac == 0) {
        return (84);
    }
    if (ac == 2 && (std::string)av[1] != "-h") {
        factSimple((std::string)av[1]);
    }
    else if ((std::string)av[1] == "-h") {
        usage();
    }
    else if (ac == 3) {
        factComplex((std::string)av[1],(std::string)av[2]);
    }
}