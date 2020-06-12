/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Ingredient
*/

#ifndef INGREDIENT_HPP_
#define INGREDIENT_HPP_

#include <string>
#include <iostream>

class Ingredient {
public:
    Ingredient(std::string name);
    ~Ingredient();
    void sub() { _num -= 1; }
    void add() { _num += 1; }
    std::string getName() { return _name; }
    int getStock() { return _num; }

protected:
private:
    int _num;
    std::string _name;
};

#endif /* !INGREDIENT_HPP_ */
