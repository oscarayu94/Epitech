/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Americana
*/

#ifndef AMERICANA_HPP_
#define AMERICANA_HPP_

#include "../IPizza.hpp"
#include "../APizza.hpp"

class Americana : public APizza {
public:
    Americana(plazza::PizzaType type, plazza::PizzaSize size);
    ~Americana();
    // bool    operator==(plazza::IPizza const &a) const;
    void    print_pizza_info();

protected:
private:
};

#endif /* !AMERICANA_HPP_ */
