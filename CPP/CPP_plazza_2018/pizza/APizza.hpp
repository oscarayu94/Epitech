/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_

#include <string>
#include "IPizza.hpp"

class APizza : public plazza::IPizza {
public:
	int getType() { return _type; }
	int getSize() { return _size; }
	std::string   getTypeName();
	std::string   getSizeName();
	APizza(plazza::PizzaType type, plazza::PizzaSize size);
	// ~APizza();

protected:
	float _time;
	plazza::PizzaType _type;
	plazza::PizzaSize _size;
private:
};

#endif /* !APIZZA_HPP_ */
