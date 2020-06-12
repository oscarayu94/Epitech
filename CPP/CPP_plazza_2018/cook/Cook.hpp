/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "../pizza/IPizza.hpp"
#include "../ingredients/Ingredient.hpp"

class Cook {
public:
    Cook(plazza::IPizza *pizza, float multiplier, std::vector<Ingredient*> stock, int kitchen_id);
    ~Cook();
    std::vector<Ingredient*>    startCooking();
    bool    isWorking() { return _working; }
    void    bake(int cookTime, plazza::PizzaType type);
    void    takeIngredient(Ingredient *ing, std::string str);
    void    takeIngredients(plazza::PizzaType type);
    void    reginaIngredients();
    void    margaritaIngredients();
    void    americanaIngredients();
    void    fantasiaIngredients();

protected:
private:
    bool    _working;
    plazza::IPizza *_pizza;
    float   _multiplier;
    std::vector<Ingredient*>    _cookingMaterials;
    std::mutex  _mutex;
    int _kitchen_id;
};

#endif /* !COOK_HPP_ */
