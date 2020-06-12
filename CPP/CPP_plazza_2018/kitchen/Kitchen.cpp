/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "../list.hpp"
#include <iostream>
#include <fstream>
#include <string>

Kitchen::Kitchen()
{
}

Kitchen::Kitchen(float cooking_time, int num_cooks, int replace_ingredients, int counter)
{
    Utils* s = Utils::getInstance();
    _cooking_time = cooking_time;
    _num_cooks = num_cooks;
    _replace_ingredients = replace_ingredients;
    _stock.push_back(new Ingredient("doe"));
    _stock.push_back(new Ingredient("tomato"));
    _stock.push_back(new Ingredient("gruyere"));
    _stock.push_back(new Ingredient("ham"));
    _stock.push_back(new Ingredient("mushrooms"));
    _stock.push_back(new Ingredient("steak"));
    _stock.push_back(new Ingredient("eggplant"));
    _stock.push_back(new Ingredient("goat cheese"));
    _stock.push_back(new Ingredient("chief love"));


    _id = counter;
    _creationSec = s->getCurrentSeconds();
    //_instructions.emplace("can you cook something else?",  isKitchenFull);

    //_instructions.insert(std::pair<std::string, ScriptFunction>("can you cook something else?", &is_kitchen_full));

}

Kitchen::~Kitchen()
{
}

bool    Kitchen::is_pizza_in_kitchen(plazza::IPizza* pizza_given)
{
    for (plazza::IPizza *pizza : _orders)
        if (pizza == pizza_given)
                return true;
    return false;
}

void    Kitchen::getOrdersInfo()
{
    for (auto p : _orders) {
        std::cout << "Pizza " << p->getTypeName() << " size " << p->getSizeName() << std::endl;
    }
}

bool    Kitchen::isKitchenFull()
{
    printf("Kitchen:%d, orderssize:%d, %d\n", _id, (int)_orders.size(), _num_cooks);

    if ((int)_orders.size() < _num_cooks * 2)
        return false;
    return true;
}

plazza::PizzaType   Kitchen::toTypeEnum(std::string type)
{
    plazza::PizzaType typ;

    if (type == "Regina" || type == "regina")
        typ = plazza::Regina;
    else if (type == "Margarita" || type == "margarita")
        typ = plazza::Margarita;
    else if (type == "Americana" || type == "americana")
        typ = plazza::Americana;
    else if (type == "Fantasia" || type == "fantasia")
        typ = plazza::Fantasia;
    return typ;
}

plazza::PizzaSize   Kitchen::toSizeEnum(std::string size)
{
    plazza::PizzaSize   siz;

    if (size == "S")
        siz = plazza::S;
    if (size == "M")
        siz = plazza::M;
    if (size == "L")
        siz = plazza::L;
    if (size == "XL")
        siz = plazza::XL;
    if (size == "XXL")
        siz = plazza::XXL;
    return siz;
}

bool    Kitchen::add_pizza(std::string order)
{
    std::string type;
    std::string size;

    type = order.substr(0, order.find(" "));
    order.erase(0, order.find(" ") + 1);
    size = order.substr(0, order.find(" "));
    order.erase(0, order.find(" ") + 1);    
    addSpecificPizza(type, size);
    return false;
}

void    Kitchen::addSpecificPizza(std::string type, std::string size)
{
    switch (toTypeEnum(type)) {
        case plazza::Regina:
            _orders.push_back(new Regina(toTypeEnum(type), toSizeEnum(size)));
            break;
        case plazza::Margarita:
            _orders.push_back(new Margarita(toTypeEnum(type), toSizeEnum(size)));
            break;
        case plazza::Americana:
            _orders.push_back(new Americana(toTypeEnum(type), toSizeEnum(size)));
            break;
        case plazza::Fantasia:
            _orders.push_back(new Fantasia(toTypeEnum(type), toSizeEnum(size)));
            break;        
    }
}

void    Kitchen::startCook()
{
    plazza::IPizza* my_order = _orders.front();
    Cook    *cook = new Cook(_orders.front() + 0, _cooking_time,_stock, _id);

    for (auto a : _stock) {
        std::cout << a->getName() << " " << a->getStock() << ", ";
    }
    std::cout << "\n";
    _stock = cook->startCooking();
    std::cout << "end start cooking, ordersize:" << _orders.size() <<"\n";
    //for (size_t i = 0; i < _orders.size(); i++)
    //    if (my_order == _orders[i])
    //        _orders.erase(_orders.begin() + i);
    
}

bool     Kitchen::answer_receptionist(std::string str)
{
    std::string instruction;
    // return true;
    instruction = str.substr(0, str.find(":"));
    str.erase(0, str.find(" ") + 1);
    if (strcmp("Order", instruction.c_str()) == 0 && isKitchenFull() == false) {
        add_pizza(str);
        _cooks.push_back(new std::thread(&Kitchen::startCook, this));
        _cooks.back()->join();
        return false;
        //Lets see if we can and do it or return false
        // return false;
    }
    return true;
}

void    Kitchen::restockIngredients()
{
    Utils* s = Utils::getInstance();
    // getCurrentSeconds();
    // std::cout << _replace_ingredients / 1000 << std::endl;
    if (s->getCurrentSeconds() >= _creationSec + (float)(_replace_ingredients / 1000)) {
        // std::cout << getCurrentSeconds() << " " << _creationSec << std::endl;
        _creationSec = s->getCurrentSeconds();
        for (auto a : _stock)
            a->add();
    }
    // _creationSec = getCurrentSeconds();
}

bool    Kitchen::infinity_loop(std::string &myfifo_read, std::string &myfifo_write)
{
    Utils* s = Utils::getInstance();
    std::string str = "d";

    for (bool val = true; val; ) {
        // Restock ingredients
        restockIngredients();
        // Read from FIFO 
        str.clear();
        str = s->read_from_fd(myfifo_read);
        std::cout << "kitchen reads:" << str << "\n";

        if (str.empty() == true) {
            //std::cout << "empty string\n";
            continue;
        }
        // Write answe to father
        if (answer_receptionist(str) == false)
            s->write_to_fd(myfifo_write, "Yes\n");
        else
            s->write_to_fd(myfifo_write, "No\n");
    }
    return true;
}
