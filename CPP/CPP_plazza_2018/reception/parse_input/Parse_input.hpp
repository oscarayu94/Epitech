/*
** EPITECH PROJECT, 2019
** parse
** File description:
** by irol
*/

#ifndef PARSE_INPUT_HPP_
#define PARSE_INPUT_HPP_

#include "../../list.hpp"
#include "../../utils/Utils.hpp"
#include "../../pizza/IPizza.hpp"
#include "../../pizza/types/Regina.hpp"
#include "../../pizza/types/Margarita.hpp"
#include "../../pizza/types/Americana.hpp"
#include "../../pizza/types/Fantasia.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

class Parse_input {
	public:
		Parse_input();
		~Parse_input();
        bool    create_pizzas(std::string &);
        std::vector<std::string>   get_pizza_order(std::string &);
        bool    get_values(int ac, char **av);
        float   getCookingTime() { return _cooking_time; }
        int getCookNum() { return _num_cooks; }
        int getReplaceTime() { return _replace_ingredient; }
        void	init(void);
        bool    checkNumber(std::string number);
        // plazza::PizzaSize  parseSize(std::string size);
        bool    checkSize(std::string size);
        // plazza::PizzaType  parseType(std::string size);
        bool    checkType(std::string size);

    protected:
    
         //as input to program
        float   _cooking_time;
        int     _num_cooks;
        int     _replace_ingredient;

        std::vector<std::string> _pizza_orders_string;
        std::vector<std::string> _pizza_orders;

    private:
};

#endif /* !PARSE_INPUT_HPP_ */
