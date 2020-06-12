/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Margarita
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_

#include "../IPizza.hpp"
#include "../APizza.hpp"

class Margarita : public APizza {
public:
    Margarita(plazza::PizzaType type, plazza::PizzaSize size);
    ~Margarita();
    // bool    operator==(plazza::IPizza const &a) const;
    void    print_pizza_info();

protected:
private:
};

#endif /* !MARGARITA_HPP_ */
