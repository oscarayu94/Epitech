/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Cook
*/

#include "Cook.hpp"

Cook::Cook(plazza::IPizza *pizza, float multiplier, std::vector<Ingredient*> stock, int kitchen_id)
    : _working(false), _pizza(pizza), _multiplier(multiplier), _cookingMaterials(stock)
{
    std::cout << "I'm a new cook!" << std::endl;
    _kitchen_id = kitchen_id;
}

void    Cook::takeIngredient(Ingredient *ing, std::string str)
{
    if (ing->getName() == str)
        ing->sub();
}

void    Cook::reginaIngredients()
{
    for (auto a : _cookingMaterials) {
        takeIngredient(a, "doe");
        takeIngredient(a, "tomato");
        takeIngredient(a, "gruyere");
        takeIngredient(a, "ham");
        takeIngredient(a, "mushrooms");
    }
}

void    Cook::margaritaIngredients()
{
    for (auto a : _cookingMaterials) {
        takeIngredient(a, "doe");
        takeIngredient(a, "tomato");
        takeIngredient(a, "gruyere");
    }
}

void    Cook::americanaIngredients()
{
    for (auto a : _cookingMaterials) {
        takeIngredient(a, "doe");
        takeIngredient(a, "tomato");
        takeIngredient(a, "gruyere");
        takeIngredient(a, "steak");
    }
}

void    Cook::fantasiaIngredients()
{
    for (auto a : _cookingMaterials) {
        takeIngredient(a, "doe");
        takeIngredient(a, "tomato");
        takeIngredient(a, "eggplant");
        takeIngredient(a, "goat cheese");
        takeIngredient(a, "chief love");
    }
}

void    Cook::takeIngredients(plazza::PizzaType type)
{
    switch (type) {
        case plazza::Regina:
            reginaIngredients();
            break;
        case plazza::Margarita:
            margaritaIngredients();
            break;
        case plazza::Americana:
            americanaIngredients();
            break;
        case plazza::Fantasia:
            fantasiaIngredients();
            break;
    }
}

void    Cook::bake(int cookTime, plazza::PizzaType type)
{
    int   bakeTime = cookTime * _multiplier;

    //_mutex.lock();
    takeIngredients(type);
    //std::this_thread::sleep_for(std::chrono::seconds(bakeTime));
    //_mutex.unlock();
}

std::vector<Ingredient*>    Cook::startCooking()
{
    _working = true;

    std::cout << "Let's cook!" << std::endl;
    switch (_pizza->getType()) {
        case plazza::Regina:
            bake(2, plazza::Regina);
            break;
        case plazza::Margarita:
            bake(1, plazza::Margarita);
            break;
        case plazza::Americana:
            bake(2, plazza::Americana);
            break;
        case plazza::Fantasia:
            bake(4, plazza::Fantasia);
            break;
    }
    std::cout << _pizza->getTypeName() << " it's done in kitchen " << _kitchen_id << "!!!!!!!!!!!!!!" << std::endl;
    _working = false;
    return _cookingMaterials;
}

Cook::~Cook()
{
}
