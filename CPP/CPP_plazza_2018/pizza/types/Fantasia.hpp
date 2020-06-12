/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Fantasia
*/

#ifndef FANTASIA_HPP_
#define FANTASIA_HPP_

#include "../IPizza.hpp"
#include "../APizza.hpp"

class Fantasia : public APizza {
public:
    Fantasia(plazza::PizzaType type, plazza::PizzaSize size);
    ~Fantasia();
    // bool    operator==(plazza::IPizza const &a) const;
    void    print_pizza_info();

protected:
private:
};

#endif /* !FANTASIA_HPP_ */
