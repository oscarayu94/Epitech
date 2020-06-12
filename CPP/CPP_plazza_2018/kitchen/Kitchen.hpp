/*
** EPITECH PROJECT, 2019
** kitchen
** File description:
** by oriol
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include "../pizza/IPizza.hpp"
#include "../cook/Cook.hpp"
#include "../list.hpp"
#include "../utils/Utils.hpp"
//typedef void (*ScriptFunction)(void); // function pointer type
//typedef std::unordered_map<std::string, ScriptFunction> my_map;
#include "../pizza/types/Regina.hpp"
#include "../pizza/types/Margarita.hpp"
#include "../pizza/types/Americana.hpp"
#include "../pizza/types/Fantasia.hpp"
#include "../ingredients/Ingredient.hpp"

class Kitchen  {
public:
    Kitchen();
    Kitchen(float cooking_time, int num_cooks, int replace_ingredients, int counter);
    ~Kitchen();
    bool    is_pizza_in_kitchen(plazza::IPizza* pizza_given);
    bool    add_pizza(std::string order);
    void    addSpecificPizza(std::string type, std::string size);
    void    getOrdersInfo();
    bool    isKitchenFull();
    bool    infinity_loop(std::string &, std::string &);
    bool    answer_receptionist(std::string );
    
    plazza::PizzaType   toTypeEnum(std::string type);
    plazza::PizzaSize   toSizeEnum(std::string size);
    
    void    startCook();
    void    restockIngredients();

protected:    
private:
    //Comon for each kitchen
    float   _cooking_time;
    int     _num_cooks;
    int     _replace_ingredients;
    int     _id;
    std::vector<plazza::IPizza*> _orders;
    std::vector<std::thread*>   _cooks;
    std::vector<Ingredient*>    _stock;
    int _creationSec;
    // std::mutex _mtx;
};

#endif /* !KITCHEN_HPP_ */
