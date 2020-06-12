/*
** EPITECH PROJECT, 2019
** parse
** File description:
** by oriol
*/

#include "Parse_input.hpp"
#include "../../list.hpp"
#include "../../kitchen/Kitchen.hpp"
#include "../../utils/Utils.hpp"

Parse_input::Parse_input()
{
    _cooking_time = 0;
    _num_cooks = 0;
    _replace_ingredient = 0;
}

Parse_input::~Parse_input()
{
}

bool    Parse_input::get_values(int ac, char **av)
{
    std::string my_string;
    try {
        if (ac != 4 || av == NULL)
            return false;
        for (int i = 1; i != 4; i++) {
            my_string = av[i];
            if (i == 1)
                _cooking_time = std::stof(my_string);
            if (i == 2)
                _num_cooks = std::stof(my_string);
            if (i == 3)
                _replace_ingredient = std::stof(my_string);
        }
    }
    catch (...) {
        return false;
    }
    if (_cooking_time < 0 || _num_cooks < 0 || _replace_ingredient < 0)
        return false;
    return true;
}

std::vector<std::string>   Parse_input::get_pizza_order(std::string &pizza_order)
{
    Utils* s = Utils::getInstance(); // Ok

    int num_semicolon = s->num_charact(pizza_order, ';');
    std::string pizza_info;
    std::size_t found;

    if ( pizza_order[0] == ' ' || pizza_order[0] == '\t') {
        int detect = pizza_order.find_first_not_of(' ');
        pizza_order = pizza_order.substr(detect,pizza_order.find_first_of(";"));
    }                

    init();
    try {
        for (int i = 0 ; i < num_semicolon + 1; i++) {
            found = pizza_order.find(";");
            if (found != std::string::npos) {
                //std::cout << "first pizza order: " << pizza_order << std::endl;
                pizza_info = pizza_order.substr(0, found);
                pizza_order.erase(0, pizza_order.find(";") + 1);
                //std::cout << "second pizza order: " << pizza_order << std::endl;
            }
            else
                pizza_info = pizza_order;
            _pizza_orders_string.push_back(pizza_info);
        }
    }
    catch (...) {
        init();
        return _pizza_orders;
    }
    //std::cout << "create_pizza\n";
    for (auto a : _pizza_orders_string)
        if (create_pizzas(a) == false)
            break;
    return _pizza_orders;
}

bool    Parse_input::checkNumber(std::string number)
{
    if (number.size() > 3) {
        //std::cout << "Too much pizzas fren" << std::endl;
        exit(84);
    }
    if (number[0] == 'x') {
        number = number.substr(1,2);
        if (isdigit(number[0])) {
            if (number[1] == '\0' || isdigit(number[1])) {
                return true;
            }
        }
        else
            return false;
    } 
    return false;
}

bool    Parse_input::create_pizzas(std::string &a)
{
    std::string   type;
    std::string   size;
    std::string   number;
    std::string msg = "Order: ";

    try {
        if ( a[0] == ' ' || a[0] == '\t') {
        int detect = a.find_first_not_of(' ');
        a = a.substr(detect,a.find_first_of(";"));
        }                
        type = a.substr(0, a.find(" "));
        a.erase(0, a.find(" ") + 1);
        size = a.substr(0, a.find(" "));
        a.erase(0, a.find(" ") + 1);
        number = a.substr(0,a.find(" "));
        a.erase(0, a.find(" ") + 1);
    }
    catch (...) {
        init();
        return false;
    }
    if (checkNumber(number) == false){
        std::cout << "Not a number" << std::endl;
       init();
    }
    else {
       number = number.substr(1,2);
        for (int i = 0; i < std::stoi(&number[0]); i++) {
            if (checkType(type) == false)
                return false;
            if (checkSize(size) == false)
                return false;
            // std::cout<< "type:" << type << ", size:" << (size) << ", number:" << (number) << "\n"; 
            // std::cout<< "type:" << parseType(type)<< ", size:" << parseSize(size) << ", number:" << std::stoi(&number[1]) << "\n"; 
            _pizza_orders.push_back(msg + type + " " + size);
        }
    }    
    return true;
}

bool  Parse_input::checkSize(std::string size)
{
    if (size == "S" || size == "M" || size == "L" || size == "XL" || size == "XXL")
        return true;
    init();
    //std::cout << "Wrong size" << std::endl;
    return false;
}

bool Parse_input::checkType(std::string type)
{
    if (type == "Regina" || type == "regina")
        return true;
    else if (type == "Margarita" || type == "margarita")
        return true;
    else if (type == "Americana" || type == "americana")
        return true;
    else if (type == "Fantasia" || type == "fantasia")
        return true;
    init();
    //std::cout << "Wrong type" << std::endl;
    return false;
}

void	Parse_input::init(void)
{
    _pizza_orders.clear();
    _pizza_orders_string.clear();
}
